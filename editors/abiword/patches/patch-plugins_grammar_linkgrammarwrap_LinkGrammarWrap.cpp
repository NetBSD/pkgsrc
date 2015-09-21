$NetBSD: patch-plugins_grammar_linkgrammarwrap_LinkGrammarWrap.cpp,v 1.1 2015/09/21 11:28:45 nros Exp $

First chunk:
Remove obsolete function call, see
http://bugzilla.abisource.com/show_bug.cgi?id=13726                                                                                                  

Other chunks:
Fix build with link-grammar-5.2.5.
http://www.abisource.com/viewvc/abiword/trunk/plugins/grammar/linkgrammarwrap/LinkGrammarWrap.cpp?r1=32836&r2=34627

--- plugins/grammar/linkgrammarwrap/LinkGrammarWrap.cpp.orig	2013-04-07 13:53:03.000000000 +0000
+++ plugins/grammar/linkgrammarwrap/LinkGrammarWrap.cpp
@@ -87,7 +87,7 @@ bool LinkGrammarWrap::parseSentence(Piec
   parse_options_set_min_null_count(m_Opts, 0);
   parse_options_set_max_null_count(m_Opts, 0);
   parse_options_set_islands_ok(m_Opts, 0);
-  parse_options_set_panic_mode(m_Opts, TRUE);
+  //parse_options_set_panic_mode(m_Opts, TRUE);
   parse_options_reset_resources(m_Opts);
   UT_sint32 num_linkages = sentence_parse(sent, m_Opts);
   bool res =  (num_linkages >= 1);
@@ -145,59 +145,57 @@ bool LinkGrammarWrap::parseSentence(Piec
 	  }
 	  AbiGrammarError * pWordMap = new  AbiGrammarError();
 	  pWordMap->m_iErrLow = iLow;
-	  pWordMap->m_iErrHigh = iLow + strlen(sentence_get_nth_word(sent, i));
+	  pWordMap->m_iErrHigh = iLow + strlen(linkage_get_word(linkage, i));
 	  pWordMap->m_iWordNum = i;
 	  vecMapOfWords.addItem(pWordMap);
 	  bool bNew = false;
-	  if(!sentence_nth_word_has_disjunction(sent, i))
+
+	  //UT_DEBUGMSG(("|%s| NULL LINK\n",sent->word[i].string));
+	  if(pErr == NULL)
+	  {
+	    pErr = new AbiGrammarError();
+	    bNew = true;
+	  }
+	  if(bNew || (pErr->m_iWordNum + 1 < i))
 	  {
-	    //UT_DEBUGMSG(("|%s| NULL LINK\n",sent->word[i].string));
-	    if(pErr == NULL)
+	    if(!bNew)
 	    {
-	      pErr = new AbiGrammarError();
-	      bNew = true;
+		  if(pErr)
+		  {
+		    delete pErr;
+		  }
+		  pErr = new AbiGrammarError();
 	    }
-	    if(bNew || (pErr->m_iWordNum + 1 < i))
+	    iHigh = iLow + strlen(linkage_get_word(linkage, i));
+	    pErr->m_iErrLow = iLow + iOff -1;
+	    pErr->m_iErrHigh = iHigh + iOff -1;
+	    if(pErr->m_iErrLow < 0)
+	    {
+		  pErr->m_iErrLow = 0;
+	    }
+	    if(pErr->m_iErrHigh < totlen-1)
 	    {
-	      if(!bNew)
-	      {
-		if(pErr)
-		{
-		  delete pErr;
-		}
-		pErr = new AbiGrammarError();
-	      }
-	      iHigh = iLow + strlen(sentence_get_nth_word(sent, i));
-	      pErr->m_iErrLow = iLow + iOff -1;
-	      pErr->m_iErrHigh = iHigh + iOff -1;
-	      if(pErr->m_iErrLow < 0)
-	      {
-		pErr->m_iErrLow = 0;
-	      }
-	      if(pErr->m_iErrHigh < totlen-1)
-	      {
 		  pErr->m_iErrHigh += 1;
-	      }
-	      pErr->m_iWordNum = i;
-	      // UT_DEBUGMSG(("Add Error %x low %d High %d\n",pErr,pErr->m_iErrLow,pErr->m_iErrHigh));
-	      pT->m_vecGrammarErrors.addItem(pErr);
-		  pErr = NULL;
 	    }
-	    else
+	    pErr->m_iWordNum = i;
+	    // UT_DEBUGMSG(("Add Error %x low %d High %d\n",pErr,pErr->m_iErrLow,pErr->m_iErrHigh));
+	    pT->m_vecGrammarErrors.addItem(pErr);
+		pErr = NULL;
+	  }
+	  else
+	  {
+	    //
+	    // Expand the sqiggle
+	    //
+	    iHigh = iLow + strlen(linkage_get_word(linkage, i)) + iOff;
+	    pErr->m_iErrHigh = iHigh;
+	    if(pErr->m_iErrHigh < totlen-1)
 	    {
-	      //
-	      // Expand the sqiggle
-	      //
-	      iHigh = iLow + strlen(sentence_get_nth_word(sent, i)) + iOff;
-	      pErr->m_iErrHigh = iHigh;
-	      if(pErr->m_iErrHigh < totlen-1)
-	      {
 		  pErr->m_iErrHigh += 1;
-	      }
-	      pErr->m_iWordNum = i;
 	    }
+	    pErr->m_iWordNum = i;
 	  }
-	  iLow += strlen(sentence_get_nth_word(sent, i));
+	  iLow += strlen(linkage_get_word(linkage, i));
 	}
 	//
 	// No NULL links but still an error , mark the whole sentence bad.
@@ -229,30 +227,6 @@ bool LinkGrammarWrap::parseSentence(Piec
 	//  }
 	UT_UTF8String sErr = linkage_get_violation_name(linkage);
 	//	UT_DEBUGMSG(("Top Level error message |%s|\n",sErr.utf8_str()));
-	UT_sint32 count = linkage_get_num_sublinkages(linkage);
-	//
-	// Find linkages with violations
-	//
-	for(i=0; i<count;i++)
-	{
-	  UT_sint32 iok = linkage_set_current_sublinkage(linkage, i);
-	  if(iok == 0)
-	    continue;
-	  UT_sint32 j = 0;
-	  UT_sint32 iNum = linkage_get_num_links(linkage);
-	  for(j=0;j< iNum;j++)
-	    //	  char * szViolation = linkage_get_violation_name(linkage);
-	  //if(szViolation != NULL)
-	  {
-            // debug disabled
-	    //UT_sint32 iLword = linkage_get_link_lword(linkage,j);
-	    //const char * szLword =  linkage_get_word(linkage,iLword);
-	    //UT_sint32 iRword = linkage_get_link_rword(linkage,j);
-	    //const char * szRword =  linkage_get_word(linkage,iRword);
-	    //UT_DEBUGMSG(("Link %d |%s| and |%s|\n",i,szLword,szRword));
-	    //UT_DEBUGMSG(("Left Word num %d Right Word num %d\n",iLword,iRword));
-	  }
-	}
 	linkage_delete(linkage);
 	for(i=0; i<  vecMapOfWords.getItemCount(); i++)
 	{
