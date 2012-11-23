$NetBSD: patch-src_wxForms_LegendPopup.cpp,v 1.1 2012/11/23 12:29:15 joerg Exp $

--- src/wxForms/LegendPopup.cpp.orig	2012-11-21 22:11:15.000000000 +0000
+++ src/wxForms/LegendPopup.cpp
@@ -166,10 +166,11 @@ void LegendPopup::CreateForm()
   titleBotSizer->Add( new wxStaticText(titleBotPanel,wxID_ANY,wxT("Font")),
                       wxSizerFlags(0).Left().Border(wxALL,2) );
   int nf = GRA_fontControl::GetCount();
-  wxString choices[nf];
+  wxString *choices = new wxString[nf];
   for( int i=0; i<nf; ++i )choices[i] = GRA_fontControl::GetFont(i)->GetFontName();
   titleFontCB_ = new wxComboBox( titleBotPanel, ID_font, wxT(""), wxDefaultPosition, wxSize(200,25), nf,
                                  choices, wxCB_READONLY );
+  delete[] choices;
   titleFontCB_->SetToolTip( wxT("choose the title font") );
   titleBotSizer->Add( titleFontCB_, wxSizerFlags(0).Left().Border(wxALL,2) );
 
