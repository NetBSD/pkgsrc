$NetBSD: patch-binaryurp_source_cache.hxx,v 1.1 2014/01/20 19:27:51 joerg Exp $

--- binaryurp/source/cache.hxx.orig	2013-10-22 17:49:23.000000000 +0000
+++ binaryurp/source/cache.hxx
@@ -25,6 +25,7 @@
 #include <cassert>
 #include <cstddef>
 #include <map>
+#include <list>
 
 #include "boost/noncopyable.hpp"
 #include "sal/types.h"
@@ -37,88 +38,57 @@ enum { size = 256, ignore = 0xFFFF };
 
 }
 
-template< typename T > class Cache: private boost::noncopyable {
+template< typename T > class Cache : private boost::noncopyable {
 public:
+    typedef sal_uInt16 IdxType;
+
     explicit Cache(std::size_t size):
-        size_(size), first_(map_.end()), last_(map_.end())
+        size_(size)
     {
         assert(size < cache::ignore);
     }
 
-    sal_uInt16 add(T const & content, bool * found) {
-        assert(found != 0);
-        typename Map::iterator i(map_.find(content));
-        *found = i != map_.end();
-        if (i == map_.end()) {
-            typename Map::size_type n = map_.size();
-            if (n < size_) {
-                i =
-                    (map_.insert(
-                        typename Map::value_type(
-                            content,
-                            Entry(
-                                static_cast< sal_uInt16 >(n), map_.end(),
-                                first_)))).
-                    first;
-                if (first_ == map_.end()) {
-                    last_ = i;
-                } else {
-                    first_->second.prev = i;
-                }
-                first_ = i;
-            } else if (last_ != map_.end()) {
-                i =
-                    (map_.insert(
-                        typename Map::value_type(
-                            content,
-                            Entry(last_->second.index, map_.end(), first_)))).
-                    first;
-                first_->second.prev = i;
-                first_ = i;
-                typename Map::iterator j(last_);
-                last_ = last_->second.prev;
-                last_->second.next = map_.end();
-                map_.erase(j);
-            } else {
-                // Reached iff size_ == 0:
-                return cache::ignore;
-            }
-        } else if (i != first_) {
-            // Move to front (reached only if size_ > 1):
-            i->second.prev->second.next = i->second.next;
-            if (i->second.next == map_.end()) {
-                last_ = i->second.prev;
-            } else {
-                i->second.next->second.prev = i->second.prev;
-            }
-            i->second.prev = map_.end();
-            i->second.next = first_;
-            first_->second.prev = i;
-            first_ = i;
-        }
-        return i->second.index;
+    IdxType add( const T& rContent, bool* pbFound) {
+	assert( pbFound != NULL);
+	if( !size_) {
+		*pbFound = false;
+		return cache::ignore;
+	}
+	// try to insert into the map
+	list_.push_front( rContent); // create a temp entry
+	typedef std::pair<typename LruList::iterator, IdxType> MappedType;
+	typedef std::pair<typename LruItMap::iterator,bool> MapPair;
+	MapPair aMP = map_.insert( MappedType( list_.begin(), 0));
+	*pbFound = !aMP.second;
+	
+	if( !aMP.second) { // insertion not needed => found the entry
+		list_.pop_front(); // remove the temp entry
+		list_.splice( list_.begin(), list_, aMP.first->first); // the found entry is moved to front
+		return aMP.first->second;
+	}
+
+	// test insertion successful => it was new so we keep it
+	IdxType n = static_cast<IdxType>( map_.size() - 1);
+	if( n >= size_) { // cache full => replace the LRU entry
+		// find the least recently used element in the map
+		typename LruItMap::iterator it = map_.find( --list_.end());
+		n = it->second;
+		map_.erase( it); // remove it from the map
+		list_.pop_back(); // remove from the list
+	}
+	aMP.first->second = n;
+	return n;
     }
 
 private:
-    struct Entry;
-
-    typedef std::map< T, Entry > Map;
-
-    struct Entry {
-        sal_uInt16 index;
-        typename Map::iterator prev;
-        typename Map::iterator next;
-
-        Entry(
-            sal_uInt16 theIndex, typename Map::iterator thePrev,
-            typename Map::iterator theNext):
-            index(theIndex), prev(thePrev), next(theNext) {}
-    };
+    typedef std::list<T> LruList; // last recently used list
+    typedef typename LruList::iterator LruListIt;
+    struct CmpT{ bool operator()( const LruListIt& rA, const LruListIt& rB) const { return (*rA<*rB);}};
+    typedef ::std::map< LruListIt, IdxType, CmpT > LruItMap; // a map into a LruList
 
     std::size_t size_;
-    Map map_;
-    typename Map::iterator first_;
-    typename Map::iterator last_;
+    LruItMap map_;
+    LruList list_;
 };
 
 }
