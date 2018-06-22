$NetBSD: patch-cups_ipp.c,v 1.1 2018/06/22 14:12:45 bouyer Exp $
From upstream: https://github.com/apple/cups/commit/18545a5e7ab478b187a0d7136ee19496ae32fc9b
 Fix regressions in ippValidateAttribute (Issue #5322, Issue #5330) 

--- cups/ipp.c.orig
+++ cups/ipp.c
@@ -5101,16 +5101,19 @@ ippValidateAttribute(
 	      break;
 	  }
 
-	  if (*ptr < ' ' || *ptr == 0x7f)
-	  {
-	    ipp_set_error(IPP_STATUS_ERROR_BAD_REQUEST, _("\"%s\": Bad text value \"%s\" - bad control character (PWG 5100.14 section 8.3)."), attr->name, attr->values[i].string.text);
-	    return (0);
-	  }
-	  else if (*ptr)
-	  {
-	    ipp_set_error(IPP_STATUS_ERROR_BAD_REQUEST, _("\"%s\": Bad text value \"%s\" - bad UTF-8 sequence (RFC 8011 section 5.1.2)."), attr->name, attr->values[i].string.text);
-	    return (0);
-	  }
+          if (*ptr)
+          {
+	    if (*ptr < ' ' || *ptr == 0x7f)
+	    {
+	      ipp_set_error(IPP_STATUS_ERROR_BAD_REQUEST, _("\"%s\": Bad text value \"%s\" - bad control character (PWG 5100.14 section 8.3)."), attr->name, attr->values[i].string.text);
+	      return (0);
+	    }
+	    else
+	    {
+	      ipp_set_error(IPP_STATUS_ERROR_BAD_REQUEST, _("\"%s\": Bad text value \"%s\" - bad UTF-8 sequence (RFC 8011 section 5.1.2)."), attr->name, attr->values[i].string.text);
+	      return (0);
+	    }
+          }
 
 	  if ((ptr - attr->values[i].string.text) > (IPP_MAX_TEXT - 1))
 	  {
@@ -5163,16 +5166,19 @@ ippValidateAttribute(
 	      break;
 	  }
 
-	  if (*ptr < ' ' || *ptr == 0x7f)
-	  {
-	    ipp_set_error(IPP_STATUS_ERROR_BAD_REQUEST, _("\"%s\": Bad name value \"%s\" - bad control character (PWG 5100.14 section 8.1)."), attr->name, attr->values[i].string.text);
-	    return (0);
-	  }
-	  else if (*ptr)
+	  if (*ptr)
 	  {
-	    ipp_set_error(IPP_STATUS_ERROR_BAD_REQUEST, _("\"%s\": Bad name value \"%s\" - bad UTF-8 sequence (RFC 8011 section 5.1.3)."), attr->name, attr->values[i].string.text);
-	    return (0);
-	  }
+	    if (*ptr < ' ' || *ptr == 0x7f)
+	    {
+	      ipp_set_error(IPP_STATUS_ERROR_BAD_REQUEST, _("\"%s\": Bad name value \"%s\" - bad control character (PWG 5100.14 section 8.1)."), attr->name, attr->values[i].string.text);
+	      return (0);
+	    }
+	    else
+	    {
+	      ipp_set_error(IPP_STATUS_ERROR_BAD_REQUEST, _("\"%s\": Bad name value \"%s\" - bad UTF-8 sequence (RFC 8011 section 5.1.3)."), attr->name, attr->values[i].string.text);
+	      return (0);
+	    }
+          }
 
 	  if ((ptr - attr->values[i].string.text) > (IPP_MAX_NAME - 1))
 	  {
