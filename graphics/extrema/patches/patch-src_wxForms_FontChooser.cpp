$NetBSD: patch-src_wxForms_FontChooser.cpp,v 1.1 2012/11/23 12:29:15 joerg Exp $

--- src/wxForms/FontChooser.cpp.orig	2012-11-21 22:08:15.000000000 +0000
+++ src/wxForms/FontChooser.cpp
@@ -101,9 +101,10 @@ void FontChooser::CreateForm()
   topSizer->Add( new wxStaticText(topPanel,wxID_ANY,wxT("Font ")), wxSizerFlags(0).Right().Border(wxTOP,5) );
   //
   int nf = GRA_fontControl::GetCount();
-  wxString choices[nf];
+  wxString *choices = new wxString[nf];
   for( int i=0; i<nf; ++i )choices[i] = GRA_fontControl::GetFont(i)->GetFontName();
   fontCB_ = new wxComboBox( topPanel, ID_font, wxT(""), wxDefaultPosition, wxSize(200,25), nf, choices, wxCB_READONLY );
+  delete[] choices;
   topSizer->Add( fontCB_, wxSizerFlags(1).Left().Border(wxALL,2) );
   topPanel->SetSizer( topSizer );
   mainSizer->Add( topPanel, wxSizerFlags(0).Expand().Border(wxALL,2) );
