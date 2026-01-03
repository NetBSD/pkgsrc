$NetBSD: patch-src_database_sql__database.cc,v 1.1 2026/01/03 10:28:11 wiz Exp $

Fix build with fmtlib 12.

--- src/database/sql_database.cc.orig	2026-01-03 10:19:17.058170945 +0000
+++ src/database/sql_database.cc
@@ -1447,7 +1447,8 @@ int SQLDatabase::ensurePathExistence(con
         *changedContainer = parentID;
 
     std::vector<std::pair<std::string, std::string>> itemMetadata;
-    itemMetadata.emplace_back(MetaEnumMapper::getMetaFieldName(MetadataFields::M_DATE), fmt::format("{:%FT%T%z}", fmt::localtime(toSeconds(fs::last_write_time(path)).count())));
+    itemMetadata.emplace_back(MetaEnumMapper::getMetaFieldName(MetadataFields::M_DATE), grbLocaltime("{:%FT%T%z}", toSeconds(fs::last_write_time(path))));
+
 
     auto f2i = converterManager->f2i();
     return createContainer(parentID, f2i->convert(path.filename()), path, OBJECT_FLAG_RESTRICTED, false, "", INVALID_OBJECT_ID, itemMetadata);
@@ -1641,7 +1642,7 @@ bool SQLDatabase::addContainer(int paren
     commit("addContainer");
 
     if (cont->getMetaData(MetadataFields::M_DATE).empty())
-        cont->addMetaData(MetadataFields::M_DATE, fmt::format("{:%FT%T%z}", fmt::localtime(cont->getMTime().count())));
+        cont->addMetaData(MetadataFields::M_DATE, grbLocaltime("{:%FT%T%z}", cont->getMTime()));
 
     *containerID = createContainer(parentContainerId, cont->getTitle(), virtualPath, cont->getFlags(), cont->isVirtual(), cont->getClass(), cont->getFlag(OBJECT_FLAG_PLAYLIST_REF) ? cont->getRefID() : INVALID_OBJECT_ID, cont->getMetaData(), cont->getResources());
     return true;
@@ -2582,7 +2583,7 @@ std::vector<std::map<std::string, std::s
         stats["name"] = row->col(0);
         stats["count"] = fmt::format("{}", row->col_int(1, -1));
         stats["playCount"] = fmt::format("{}", row->col_int(2, -1));
-        stats["last"] = fmt::format("{:%a %b %d %H:%M:%S %Y}", fmt::localtime(std::chrono::seconds(row->col_int(3, 0)).count()));
+        stats["last"] = grbLocaltime("{:%a %b %d %H:%M:%S %Y}", std::chrono::seconds(row->col_int(3, 0)));
         stats["bookmarks"] = fmt::format("{}", row->col_int(4, -1));
         result.push_back(std::move(stats));
     }
@@ -2708,7 +2709,7 @@ std::shared_ptr<AutoscanDirectory> SQLDa
         interval = std::stoi(getCol(row, AutoscanColumn::Interval));
     auto lastModified = std::chrono::seconds(std::stol(getCol(row, AutoscanColumn::LastModified)));
 
-    log_info("Loading autoscan location: {}; recursive: {}, mt: {}/{}, last_modified: {}", location.c_str(), recursive, mt, AutoscanDirectory::mapMediaType(mt), lastModified > std::chrono::seconds::zero() ? fmt::format("{:%Y-%m-%d %H:%M:%S}", fmt::localtime(lastModified.count())) : "unset");
+    log_info("Loading autoscan location: {}; recursive: {}, mt: {}/{}, last_modified: {}", location.c_str(), recursive, mt, AutoscanDirectory::mapMediaType(mt), lastModified > std::chrono::seconds::zero() ? grbLocaltime("{:%Y-%m-%d %H:%M:%S}", lastModified) : "unset");
 
     auto dir = std::make_shared<AutoscanDirectory>(location, mode, recursive, persistent, interval, hidden, followSymlinks, mt, containerMap);
     dir->setObjectID(objectID);
