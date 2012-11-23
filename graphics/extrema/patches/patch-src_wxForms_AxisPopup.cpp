$NetBSD: patch-src_wxForms_AxisPopup.cpp,v 1.1 2012/11/23 12:29:15 joerg Exp $

--- src/wxForms/AxisPopup.cpp.orig	2012-11-21 22:06:14.000000000 +0000
+++ src/wxForms/AxisPopup.cpp
@@ -214,9 +214,10 @@ void AxisPopup::MakeNumbersPanel()
   
   sizer->Add( new wxStaticText(panel,wxID_ANY,wxT("Font ")), wxSizerFlags(0).Left().Border(wxTOP,5) );
   int nf = GRA_fontControl::GetCount();
-  wxString choices[nf];
+  wxString *choices = new wxString[nf];
   for( int i=0; i<nf; ++i )choices[i] = GRA_fontControl::GetFont(i)->GetFontName();
   nFontCB_ = new wxComboBox( panel, ID_numbersFont, wxT(""), wxDefaultPosition, wxSize(200,25), nf, choices, wxCB_READONLY );
+  delete[] choices;
   nFontCB_->SetToolTip( wxT("choose the axis numbers font") );
   sizer->Add( nFontCB_, wxSizerFlags(0).Left().Border(wxALL,2) );
   
@@ -268,9 +269,10 @@ void AxisPopup::MakeLabelPanel()
   
   topSizer->Add( new wxStaticText(topPanel,wxID_ANY,wxT("Font ")), wxSizerFlags(0).Left().Border(wxTOP,5) );
   int nf = GRA_fontControl::GetCount();
-  wxString choices[nf];
+  wxString *choices = new wxString[nf];
   for( int i=0; i<nf; ++i )choices[i] = GRA_fontControl::GetFont(i)->GetFontName();
   lFontCB_ = new wxComboBox( topPanel, ID_labelFont, wxT(""), wxDefaultPosition, wxSize(200,25), nf, choices, wxCB_READONLY );
+  delete[] choices;
   lFontCB_->SetToolTip( wxT("choose the axis label font") );
   topSizer->Add( lFontCB_, wxSizerFlags(0).Left().Border(wxALL,2) );
   
