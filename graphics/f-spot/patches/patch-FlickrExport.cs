$NetBSD: patch-FlickrExport.cs,v 1.1 2015/05/23 10:33:01 kefren Exp $

Make it compile with newer version of flickrnet

--- src/Extensions/Exporters/FSpot.Exporters.Flickr/FSpot.Exporters.Flickr/FlickrExport.cs.orig	2015-05-23 13:03:00.000000000 +0300
+++ src/Extensions/Exporters/FSpot.Exporters.Flickr/FSpot.Exporters.Flickr/FlickrExport.cs	2015-05-23 13:07:29.000000000 +0300
@@ -124,9 +124,9 @@
 					do_export_flickr.Sensitive = true;
 					auth_flickr.Sensitive = true;
 					auth_label.Text = System.String.Format (Catalog.GetString ("Welcome {0} you are connected to {1}"),
-										auth.User.Username,
+										auth.User.UserName,
 										current_service.Name);
-					auth_flickr.Label = String.Format (Catalog.GetString ("Sign in as a different user"), auth.User.Username);
+					auth_flickr.Label = String.Format (Catalog.GetString ("Sign in as a different user"), auth.User.UserName);
 					used_bandwidth.Visible = !fr.Connection.PeopleGetUploadStatus().IsPro &&
 									fr.Connection.PeopleGetUploadStatus().BandwidthMax > 0;
 					if (used_bandwidth.Visible) {
@@ -326,7 +326,7 @@
 				progress_dialog.ProgressText = String.Format (Catalog.GetString ("Waiting for response {0} of {1}"),
 									      photo_index, selection.Count);
 			}
-			progress_dialog.Fraction = (photo_index - 1.0 + (args.Bytes / (double) info.Length)) / (double) selection.Count;
+			progress_dialog.Fraction = (photo_index - 1.0 + (args.BytesSent / (double) info.Length)) / (double) selection.Count;
 		}
 
 		private class DateComparer : IComparer
@@ -370,7 +370,7 @@
 						App.Instance.Database.Exports.Create ((photo as FSpot.Photo).Id,
 									      (photo as FSpot.Photo).DefaultVersionId,
 									      ExportStore.FlickrExportType,
-									      auth.User.UserId + ":" + auth.User.Username + ":" + current_service.Name + ":" + id);
+									      auth.User.UserId + ":" + auth.User.UserName + ":" + current_service.Name + ":" + id);
 
 				} catch (System.Exception e) {
 					progress_dialog.Message = String.Format (Catalog.GetString ("Error Uploading To {0}: {1}"),
@@ -393,7 +393,7 @@
 			if (open && ids.Count != 0) {
 				string view_url;
 				if (current_service.Name == "Zooomr.com")
-					view_url = string.Format ("http://www.{0}/photos/{1}/", current_service.Name, auth.User.Username);
+					view_url = string.Format ("http://www.{0}/photos/{1}/", current_service.Name, auth.User.UserName);
 				else {
 					view_url = string.Format ("http://www.{0}/tools/uploader_edit.gne?ids", current_service.Name);
 					bool first = true;
