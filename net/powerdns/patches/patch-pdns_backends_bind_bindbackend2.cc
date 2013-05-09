$NetBSD: patch-pdns_backends_bind_bindbackend2.cc,v 1.2 2013/05/09 20:06:53 joerg Exp $

Limit inclusion of boost headers to only those necessary to avoid conflicting
types errors on Solaris.

--- pdns/backends/bind/bindbackend2.cc.orig	2012-01-05 13:54:51.000000000 +0000
+++ pdns/backends/bind/bindbackend2.cc
@@ -26,8 +26,8 @@
 #include <fstream>
 #include <fcntl.h>
 #include <sstream>
-#include <boost/bind.hpp>
-#include <boost/algorithm/string.hpp>
+#include <boost/algorithm/string/erase.hpp>
+#include <boost/algorithm/string/trim.hpp>
 using namespace std;
 
 #include "dns.hh"
@@ -51,15 +51,15 @@ using namespace std;
 */
 
 // this map contains BB2DomainInfo structs, each of which contains a *pointer* to domain data
-shared_ptr<Bind2Backend::State> Bind2Backend::s_state;
+boost::shared_ptr<Bind2Backend::State> Bind2Backend::s_state;
 pthread_mutex_t Bind2Backend::s_state_swap_lock=PTHREAD_MUTEX_INITIALIZER;
 
 
 /* the model is that all our state hides in s_state. This State instance consists of the id_zone_map, which contains all our zone information, indexed by id.
    Then there is the name_id_map, which allows us to map a query to a zone id.
 
-   The s_state is never written to, and it is a reference counted shared_ptr. Any function which needs to access the state
-   should do so by making a shared_ptr copy of it, and do all its work on that copy.
+   The s_state is never written to, and it is a reference counted boost::shared_ptr. Any function which needs to access the state
+   should do so by making a boost::shared_ptr copy of it, and do all its work on that copy.
 
    When I said s_state is never written to, I lied. No elements are ever added to it, or removed from it.
    Its values however may be changed, but not the keys. 
@@ -67,8 +67,8 @@ pthread_mutex_t Bind2Backend::s_state_sw
    When it is necessary to change the State, a deep copy is made, which is changed. Afterwards, 
    the s_state pointer is made to point to the new State.
 
-   Anybody who is currently accessing the original holds a reference counted handle (shared_ptr) to it, which means it will stay around
-   To save memory, we hold the records as a shared_ptr as well.
+   Anybody who is currently accessing the original holds a reference counted handle (boost::shared_ptr) to it, which means it will stay around
+   To save memory, we hold the records as a boost::shared_ptr as well.
 
    Changes made to s_state directly should take the s_state_lock, so as to prevent writing to a stale copy.
 */
@@ -140,9 +140,9 @@ void Bind2Backend::setFresh(uint32_t dom
   s_state->id_zone_map[domain_id].d_lastcheck=time(0);
 }
 
-shared_ptr<Bind2Backend::State> Bind2Backend::getState()
+boost::shared_ptr<Bind2Backend::State> Bind2Backend::getState()
 {
-  shared_ptr<State> ret;
+  boost::shared_ptr<State> ret;
   {
     Lock l(&s_state_swap_lock);
     ret = s_state; // is only read from
@@ -153,7 +153,7 @@ shared_ptr<Bind2Backend::State> Bind2Bac
 
 bool Bind2Backend::startTransaction(const string &qname, int id)
 {
-  shared_ptr<State> state = getState(); 
+  boost::shared_ptr<State> state = getState(); 
 
   const BB2DomainInfo &bbd=state->id_zone_map[d_transaction_id=id];
 
@@ -177,7 +177,7 @@ bool Bind2Backend::commitTransaction()
   delete d_of;
   d_of=0;
   
-  shared_ptr<State> state = getState(); 
+  boost::shared_ptr<State> state = getState(); 
 
   // this might fail if s_state was cycled during the AXFR
   if(rename(d_transaction_tmpname.c_str(), state->id_zone_map[d_transaction_id].d_filename.c_str())<0)
@@ -206,7 +206,7 @@ bool Bind2Backend::feedRecord(const DNSR
 {
   string qname=r.qname;
 
-  shared_ptr<State> state = getState(); 
+  boost::shared_ptr<State> state = getState(); 
   string domain = state->id_zone_map[d_transaction_id].d_name;
 
   if(!stripDomainSuffix(&qname,domain)) 
@@ -239,7 +239,7 @@ bool Bind2Backend::feedRecord(const DNSR
 void Bind2Backend::getUpdatedMasters(vector<DomainInfo> *changedDomains)
 {
   SOAData soadata;
-  shared_ptr<State> state = getState(); 
+  boost::shared_ptr<State> state = getState(); 
 
   for(id_zone_map_t::const_iterator i = state->id_zone_map.begin(); i != state->id_zone_map.end() ; ++i) {
     if(!i->second.d_masters.empty())
@@ -268,7 +268,7 @@ void Bind2Backend::getUpdatedMasters(vec
 
 void Bind2Backend::getUnfreshSlaveInfos(vector<DomainInfo> *unfreshDomains)
 {
-  shared_ptr<State> state = getState(); 
+  boost::shared_ptr<State> state = getState(); 
   for(id_zone_map_t::const_iterator i = state->id_zone_map.begin(); i != state->id_zone_map.end() ; ++i) {
     if(i->second.d_masters.empty())
       continue;
@@ -296,7 +296,7 @@ void Bind2Backend::getUnfreshSlaveInfos(
 
 bool Bind2Backend::getDomainInfo(const string &domain, DomainInfo &di)
 {
-  shared_ptr<State> state = getState(); 
+  boost::shared_ptr<State> state = getState(); 
   for(id_zone_map_t::const_iterator i = state->id_zone_map.begin(); i != state->id_zone_map.end() ; ++i) {
     if(i->second.d_name==domain) {
       di.id=i->first;
@@ -341,7 +341,7 @@ static string canonic(string ret)
 /** THIS IS AN INTERNAL FUNCTION! It does moadnsparser prio impedence matching
     This function adds a record to a domain with a certain id. 
     Much of the complication is due to the efforts to benefit from std::string reference counting copy on write semantics */
-void Bind2Backend::insert(shared_ptr<State> stage, int id, const string &qnameu, const QType &qtype, const string &content, int ttl=300, int prio=25)
+void Bind2Backend::insert(boost::shared_ptr<State> stage, int id, const string &qnameu, const QType &qtype, const string &content, int ttl=300, int prio=25)
 {
   BB2DomainInfo bb2 = stage->id_zone_map[id];
   Bind2DNSRecord bdr;
@@ -393,7 +393,7 @@ void Bind2Backend::reload()
 
 string Bind2Backend::DLReloadNowHandler(const vector<string>&parts, Utility::pid_t ppid)
 {
-  shared_ptr<State> state = getState(); 
+  boost::shared_ptr<State> state = getState(); 
   ostringstream ret;
 
   for(vector<string>::const_iterator i=parts.begin()+1;i<parts.end();++i) {
@@ -415,7 +415,7 @@ string Bind2Backend::DLReloadNowHandler(
 string Bind2Backend::DLDomStatusHandler(const vector<string>&parts, Utility::pid_t ppid)
 {
   ostringstream ret;
-  shared_ptr<State> state = getState(); 
+  boost::shared_ptr<State> state = getState(); 
       
   if(parts.size() > 1) {
     for(vector<string>::const_iterator i=parts.begin()+1;i<parts.end();++i) {
@@ -440,7 +440,7 @@ string Bind2Backend::DLDomStatusHandler(
 
 string Bind2Backend::DLListRejectsHandler(const vector<string>&parts, Utility::pid_t ppid)
 {
-  shared_ptr<State> state = getState(); 
+  boost::shared_ptr<State> state = getState(); 
 
   ostringstream ret;
   for(id_zone_map_t::iterator j = state->id_zone_map.begin(); j != state->id_zone_map.end(); ++j) 
@@ -464,7 +464,7 @@ Bind2Backend::Bind2Backend(const string 
     return;
   }
   s_first=0;
-  s_state = shared_ptr<State>(new State);
+  s_state = boost::shared_ptr<State>(new State);
   loadConfig();
 
   extern DynListener *dl;
@@ -504,7 +504,7 @@ void Bind2Backend::loadConfig(string* st
   
   static int domain_id=1;
 
-  shared_ptr<State> staging = shared_ptr<State>(new State);
+  boost::shared_ptr<State> staging = boost::shared_ptr<State>(new State);
 
   if(!getArg("config").empty()) {
     BindParser BP;
@@ -555,7 +555,7 @@ void Bind2Backend::loadConfig(string* st
 	  bbd->d_id=domain_id++;
 	
 	  // this isn't necessary, we do this on the actual load
-	  //	  bbd->d_records=shared_ptr<vector<Bind2DNSRecord> > (new vector<Bind2DNSRecord>);
+	  //	  bbd->d_records=boost::shared_ptr<vector<Bind2DNSRecord> > (new vector<Bind2DNSRecord>);
 
 	  bbd->setCheckInterval(getArgAsNum("check-interval"));
 	  bbd->d_lastnotified=0;
@@ -578,7 +578,7 @@ void Bind2Backend::loadConfig(string* st
 	  
 	  try {
 	    // we need to allocate a new vector so we don't kill the original, which is still in use!
-	    bbd->d_records=shared_ptr<vector<Bind2DNSRecord> > (new vector<Bind2DNSRecord>); 
+	    bbd->d_records=boost::shared_ptr<vector<Bind2DNSRecord> > (new vector<Bind2DNSRecord>); 
 
 	    ZoneParserTNG zpt(i->filename, i->name, BP.getDirectory());
 	    DNSResourceRecord rr;
@@ -681,7 +681,7 @@ void Bind2Backend::loadConfig(string* st
 void Bind2Backend::nukeZoneRecords(BB2DomainInfo *bbd)
 {
   bbd->d_loaded=0; // block further access
-  bbd->d_records = shared_ptr<vector<Bind2DNSRecord> > (new vector<Bind2DNSRecord>);
+  bbd->d_records = boost::shared_ptr<vector<Bind2DNSRecord> > (new vector<Bind2DNSRecord>);
 }
 
 
@@ -689,14 +689,14 @@ void Bind2Backend::queueReload(BB2Domain
 {
   Lock l(&s_state_lock);
 
-  shared_ptr<State> staging(new State);
+  boost::shared_ptr<State> staging(new State);
 
   // we reload *now* for the time being
 
   try {
     nukeZoneRecords(bbd); // ? do we need this?
     staging->id_zone_map[bbd->d_id]=s_state->id_zone_map[bbd->d_id];
-    staging->id_zone_map[bbd->d_id].d_records=shared_ptr<vector<Bind2DNSRecord> > (new vector<Bind2DNSRecord>);  // nuke it
+    staging->id_zone_map[bbd->d_id].d_records=boost::shared_ptr<vector<Bind2DNSRecord> > (new vector<Bind2DNSRecord>);  // nuke it
 
     ZoneParserTNG zpt(bbd->d_filename, bbd->d_name, s_binddirectory);
     DNSResourceRecord rr;
@@ -740,7 +740,7 @@ void Bind2Backend::lookup(const QType &q
   if(mustlog) 
     L<<Logger::Warning<<"Lookup for '"<<qtype.getName()<<"' of '"<<domain<<"'"<<endl;
 
-  shared_ptr<State> state = getState(); 
+  boost::shared_ptr<State> state = getState(); 
 
   name_id_map_t::const_iterator iditer;
   while((iditer=state->name_id_map.find(domain)) == state->name_id_map.end() && chopOff(domain))
@@ -873,7 +873,7 @@ bool Bind2Backend::handle::get_normal(DN
 
 bool Bind2Backend::list(const string &target, int id)
 {
-  shared_ptr<State> state = getState(); 
+  boost::shared_ptr<State> state = getState(); 
   if(!state->id_zone_map.count(id))
     return false;
 
@@ -908,7 +908,7 @@ bool Bind2Backend::handle::get_list(DNSR
 
 bool Bind2Backend::isMaster(const string &name, const string &ip)
 {
-  shared_ptr<State> state = getState(); 
+  boost::shared_ptr<State> state = getState(); 
   for(id_zone_map_t::iterator j=state->id_zone_map.begin();j!=state->id_zone_map.end();++j) {
     if(j->second.d_name==name) {
       for(vector<string>::const_iterator iter = j->second.d_masters.begin(); iter != j->second.d_masters.end(); ++iter)
@@ -992,7 +992,7 @@ bool Bind2Backend::createSlaveDomain(con
   
   BB2DomainInfo &bbd = s_state->id_zone_map[newid];
 
-  bbd.d_records = shared_ptr<vector<Bind2DNSRecord> >(new vector<Bind2DNSRecord>);
+  bbd.d_records = boost::shared_ptr<vector<Bind2DNSRecord> >(new vector<Bind2DNSRecord>);
   bbd.d_name = domain;
   bbd.setCheckInterval(getArgAsNum("check-interval"));
   bbd.d_masters.push_back(ip);
