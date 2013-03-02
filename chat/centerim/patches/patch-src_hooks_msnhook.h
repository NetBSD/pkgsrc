$NetBSD: patch-src_hooks_msnhook.h,v 1.1 2013/03/02 18:20:19 joerg Exp $

--- src/hooks/msnhook.h.orig	2009-08-27 11:16:41.000000000 +0000
+++ src/hooks/msnhook.h
@@ -61,43 +61,7 @@ class msncallbacks : public MSN::Callbac
 };
 
 class msnhook : public abstracthook {
-
-    friend void msncallbacks::registerSocket(int s, int reading, int writing);
-    friend void msncallbacks::unregisterSocket(int s);
-    friend void msncallbacks::showError(MSN::Connection * conn, string msg);
-    friend void msncallbacks::buddyChangedStatus(MSN::Connection * conn, MSN::Passport buddy, string friendlyname, MSN::BuddyStatus state);
-    friend void msncallbacks::buddyOffline(MSN::Connection * conn, MSN::Passport buddy);
-    friend void msncallbacks::log(int writing, const char* buf);
-    friend void msncallbacks::gotFriendlyName(MSN::Connection * conn, string friendlyname);
-    friend void msncallbacks::gotBuddyListInfo(MSN::NotificationServerConnection * conn, MSN::ListSyncInfo * data);
-    friend void msncallbacks::gotLatestListSerial(MSN::Connection * conn, int serial);
-    friend void msncallbacks::gotGTC(MSN::Connection * conn, char c);
-    friend void msncallbacks::gotBLP(MSN::Connection * conn, char c);
-    friend void msncallbacks::gotNewReverseListEntry(MSN::Connection * conn, MSN::Passport buddy, std::string friendlyname);
-    friend void msncallbacks::addedListEntry(MSN::Connection * conn, std::string list, MSN::Passport buddy, int groupID);
-    friend void msncallbacks::removedListEntry(MSN::Connection * conn, std::string list, MSN::Passport buddy, int groupID);
-    friend void msncallbacks::addedGroup(MSN::Connection * conn, string groupName, int groupID);
-    friend void msncallbacks::removedGroup(MSN::Connection * conn, int groupID);
-    friend void msncallbacks::renamedGroup(MSN::Connection * conn, int groupID, string newGroupName);
-    friend void msncallbacks::gotSwitchboard(MSN::SwitchboardServerConnection * conn, const void * tag);
-    friend void msncallbacks::buddyJoinedConversation(MSN::SwitchboardServerConnection * conn, MSN::Passport buddy, std::string friendlyname, int is_initial);
-    friend void msncallbacks::buddyLeftConversation(MSN::SwitchboardServerConnection * conn, MSN::Passport buddy);
-    friend void msncallbacks::gotInstantMessage(MSN::SwitchboardServerConnection * conn, MSN::Passport buddy, std::string friendlyname, MSN::Message * msg);
-    friend void msncallbacks::failedSendingMessage(MSN::Connection * conn);
-    friend void msncallbacks::buddyTyping(MSN::Connection * conn, MSN::Passport buddy, std::string friendlyname);
-    friend void msncallbacks::gotInitialEmailNotification(MSN::Connection * conn, int unread_inbox, int unread_folders);
-    friend void msncallbacks::gotNewEmailNotification(MSN::Connection * conn, string from, string subject);
-    friend void msncallbacks::gotFileTransferInvitation(MSN::Connection * conn, MSN::Passport buddy, std::string friendlyname, MSN::FileTransferInvitation * inv);
-    friend void msncallbacks::fileTransferProgress(MSN::FileTransferInvitation * inv, string status, unsigned long recv, unsigned long total);
-    friend void msncallbacks::fileTransferFailed(MSN::FileTransferInvitation * inv, int error, string message);
-    friend void msncallbacks::fileTransferSucceeded(MSN::FileTransferInvitation * inv);
-    friend void msncallbacks::gotNewConnection(MSN::Connection * conn);
-    friend void msncallbacks::closingConnection(MSN::Connection * conn);
-    friend void msncallbacks::changedStatus(MSN::Connection * conn, MSN::BuddyStatus state);
-    friend int msncallbacks::connectToServer(string server, int port, bool *connected);
-    friend int msncallbacks::listenOnPort(int port);
-    friend string msncallbacks::getOurIP();
-    friend string msncallbacks::getSecureHTTPProxy();
+    friend class msncallbacks;
 
     protected:
 	imstatus ourstatus;
