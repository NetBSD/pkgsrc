$NetBSD: patch-src_mergeresultwindow.cpp,v 1.1 2020/01/16 02:37:30 gutteridge Exp $

Fix missing menu items. Patch via Fedora:
https://src.fedoraproject.org/rpms/kdiff3/c/bc38b46ef5c96b2b7800e1195b3895527bceea65

--- src/mergeresultwindow.cpp.orig	2019-05-18 01:01:30.000000000 +0000
+++ src/mergeresultwindow.cpp
@@ -55,6 +55,16 @@ int g_bAutoSolve = true;
 
 #undef leftInfoWidth
 
+QAction* MergeResultWindow::chooseAEverywhere = nullptr;
+QAction* MergeResultWindow::chooseBEverywhere = nullptr;
+QAction* MergeResultWindow::chooseCEverywhere = nullptr;
+QAction* MergeResultWindow::chooseAForUnsolvedConflicts = nullptr;
+QAction* MergeResultWindow::chooseBForUnsolvedConflicts = nullptr;
+QAction* MergeResultWindow::chooseCForUnsolvedConflicts = nullptr;
+QAction* MergeResultWindow::chooseAForUnsolvedWhiteSpaceConflicts = nullptr;
+QAction* MergeResultWindow::chooseBForUnsolvedWhiteSpaceConflicts = nullptr;
+QAction* MergeResultWindow::chooseCForUnsolvedWhiteSpaceConflicts = nullptr;
+
 MergeResultWindow::MergeResultWindow(
     QWidget* pParent,
     Options* pOptions,
@@ -148,6 +158,8 @@ void MergeResultWindow::init(
     showUnsolvedConflictsStatusMessage();
 }
 
+//This must be called before KXMLGui::SetXMLFile and friends or the actions will not be shown in the menu.
+//At that point in startup we don't have a MergeResultWindow object so we cannot connect the signals yet.
 void MergeResultWindow::initActions(KActionCollection* ac)
 {
     if(ac == nullptr){
@@ -155,15 +167,30 @@ void MergeResultWindow::initActions(KAct
         exit(-1);//we cannot recover from this.
     }
 
-    chooseAEverywhere = GuiUtils::createAction<QAction>(i18n("Choose A Everywhere"), QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_1), this, &MergeResultWindow::slotChooseAEverywhere, ac, "merge_choose_a_everywhere");
-    chooseBEverywhere = GuiUtils::createAction<QAction>(i18n("Choose B Everywhere"), QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_2), this, &MergeResultWindow::slotChooseBEverywhere, ac, "merge_choose_b_everywhere");
-    chooseCEverywhere = GuiUtils::createAction<QAction>(i18n("Choose C Everywhere"), QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_3), this, &MergeResultWindow::slotChooseCEverywhere, ac, "merge_choose_c_everywhere");
-    chooseAForUnsolvedConflicts = GuiUtils::createAction<QAction>(i18n("Choose A for All Unsolved Conflicts"), this, &MergeResultWindow::slotChooseAForUnsolvedConflicts, ac, "merge_choose_a_for_unsolved_conflicts");
-    chooseBForUnsolvedConflicts = GuiUtils::createAction<QAction>(i18n("Choose B for All Unsolved Conflicts"), this, &MergeResultWindow::slotChooseBForUnsolvedConflicts, ac, "merge_choose_b_for_unsolved_conflicts");
-    chooseCForUnsolvedConflicts = GuiUtils::createAction<QAction>(i18n("Choose C for All Unsolved Conflicts"), this, &MergeResultWindow::slotChooseCForUnsolvedConflicts, ac, "merge_choose_c_for_unsolved_conflicts");
-    chooseAForUnsolvedWhiteSpaceConflicts = GuiUtils::createAction<QAction>(i18n("Choose A for All Unsolved Whitespace Conflicts"), this, &MergeResultWindow::slotChooseAForUnsolvedWhiteSpaceConflicts, ac, "merge_choose_a_for_unsolved_whitespace_conflicts");
-    chooseBForUnsolvedWhiteSpaceConflicts = GuiUtils::createAction<QAction>(i18n("Choose B for All Unsolved Whitespace Conflicts"), this, &MergeResultWindow::slotChooseBForUnsolvedWhiteSpaceConflicts, ac, "merge_choose_b_for_unsolved_whitespace_conflicts");
-    chooseCForUnsolvedWhiteSpaceConflicts = GuiUtils::createAction<QAction>(i18n("Choose C for All Unsolved Whitespace Conflicts"), this, &MergeResultWindow::slotChooseCForUnsolvedWhiteSpaceConflicts, ac, "merge_choose_c_for_unsolved_whitespace_conflicts");
+    chooseAEverywhere = GuiUtils::createAction<QAction>(i18n("Choose A Everywhere"), QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_1), ac, "merge_choose_a_everywhere");
+    chooseBEverywhere = GuiUtils::createAction<QAction>(i18n("Choose B Everywhere"), QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_2), ac, "merge_choose_b_everywhere");
+    chooseCEverywhere = GuiUtils::createAction<QAction>(i18n("Choose C Everywhere"), QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_3), ac, "merge_choose_c_everywhere");
+    chooseAForUnsolvedConflicts = GuiUtils::createAction<QAction>(i18n("Choose A for All Unsolved Conflicts"), ac, "merge_choose_a_for_unsolved_conflicts");
+    chooseBForUnsolvedConflicts = GuiUtils::createAction<QAction>(i18n("Choose B for All Unsolved Conflicts"), ac, "merge_choose_b_for_unsolved_conflicts");
+    chooseCForUnsolvedConflicts = GuiUtils::createAction<QAction>(i18n("Choose C for All Unsolved Conflicts"), ac, "merge_choose_c_for_unsolved_conflicts");
+    chooseAForUnsolvedWhiteSpaceConflicts = GuiUtils::createAction<QAction>(i18n("Choose A for All Unsolved Whitespace Conflicts"), ac, "merge_choose_a_for_unsolved_whitespace_conflicts");
+    chooseBForUnsolvedWhiteSpaceConflicts = GuiUtils::createAction<QAction>(i18n("Choose B for All Unsolved Whitespace Conflicts"), ac, "merge_choose_b_for_unsolved_whitespace_conflicts");
+    chooseCForUnsolvedWhiteSpaceConflicts = GuiUtils::createAction<QAction>(i18n("Choose C for All Unsolved Whitespace Conflicts"), ac, "merge_choose_c_for_unsolved_whitespace_conflicts");
+}
+
+void MergeResultWindow::connectActions()
+{
+    QObject::connect(chooseAEverywhere, &QAction::triggered, this, &MergeResultWindow::slotChooseAEverywhere);
+    QObject::connect(chooseBEverywhere, &QAction::triggered, this, &MergeResultWindow::slotChooseBEverywhere);
+    QObject::connect(chooseCEverywhere, &QAction::triggered, this, &MergeResultWindow::slotChooseCEverywhere);
+
+    QObject::connect(chooseAForUnsolvedConflicts, &QAction::triggered, this, &MergeResultWindow::slotChooseAForUnsolvedConflicts);
+    QObject::connect(chooseBForUnsolvedConflicts, &QAction::triggered, this, &MergeResultWindow::slotChooseBForUnsolvedConflicts);
+    QObject::connect(chooseCForUnsolvedConflicts, &QAction::triggered, this, &MergeResultWindow::slotChooseCForUnsolvedConflicts);
+
+    QObject::connect(chooseAForUnsolvedWhiteSpaceConflicts, &QAction::triggered, this, &MergeResultWindow::slotChooseAForUnsolvedWhiteSpaceConflicts);
+    QObject::connect(chooseBForUnsolvedWhiteSpaceConflicts, &QAction::triggered, this, &MergeResultWindow::slotChooseBForUnsolvedWhiteSpaceConflicts);
+    QObject::connect(chooseCForUnsolvedWhiteSpaceConflicts, &QAction::triggered, this, &MergeResultWindow::slotChooseCForUnsolvedWhiteSpaceConflicts);
 }
 
 void MergeResultWindow::showUnsolvedConflictsStatusMessage()
