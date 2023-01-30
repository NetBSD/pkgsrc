$NetBSD: patch-src_FlightCrew_Validators_SaxSchemaValidator.cpp,v 1.1 2023/01/30 11:46:03 wiz Exp $

Work around
error: 'scoped_ptr' is not a member of 'boost'
appearing with boost 1.81.0

--- src/FlightCrew/Validators/SaxSchemaValidator.cpp.orig	2011-08-11 21:03:56.000000000 +0000
+++ src/FlightCrew/Validators/SaxSchemaValidator.cpp
@@ -35,7 +35,7 @@ std::vector< Result > SaxSchemaValidator
     const std::string &external_schema_location,
     const std::vector< const xc::MemBufInputSource* > &schemas )
 {
-    boost::scoped_ptr< xc::SAX2XMLReader > parser( xc::XMLReaderFactory::createXMLReader() );
+    std::shared_ptr< xc::SAX2XMLReader > parser( xc::XMLReaderFactory::createXMLReader() );
 
     parser->setFeature( xc::XMLUni::fgSAX2CoreValidation,            true  );
     parser->setFeature( xc::XMLUni::fgXercesLoadSchema,              false );
