$NetBSD: patch-src_wxForms_TextPopup.cpp,v 1.1 2012/11/23 12:29:15 joerg Exp $

--- src/wxForms/TextPopup.cpp.orig	2012-11-21 22:13:23.000000000 +0000
+++ src/wxForms/TextPopup.cpp
@@ -107,10 +107,11 @@ void TextPopup::CreateForm()
   //
   fSizer->Add( new wxStaticText(fPanel,wxID_ANY,wxT("Font")), wxSizerFlags(0).Left().Border(wxTOP,2) );
   int nf = GRA_fontControl::GetCount();
-  wxString choices[nf];
+  wxString *choices = new wxString[nf];
   for( int i=0; i<nf; ++i )choices[i] = GRA_fontControl::GetFont(i)->GetFontName();
   fontCB_ = new wxComboBox( fPanel, ID_font, wxT(""), wxDefaultPosition, wxSize(200,25), nf,
                             choices, wxCB_READONLY );
+  delete[] choices;
   fontCB_->SetToolTip( wxT("choose the text font") );
   fSizer->Add( fontCB_, wxSizerFlags(0).Left().Border(wxALL,2) );
   
