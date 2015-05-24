$NetBSD: patch-FlickrRemote.cs,v 1.2 2015/05/24 06:50:14 kefren Exp $

Make it compile with newer flickrnet

--- src/Extensions/Exporters/FSpot.Exporters.Flickr/FSpot.Exporters.Flickr/FlickrRemote.cs.orig	2010-12-19 15:34:42.000000000 +0200
+++ src/Extensions/Exporters/FSpot.Exporters.Flickr/FSpot.Exporters.Flickr/FlickrRemote.cs	2015-05-23 13:25:26.000000000 +0300
@@ -11,6 +11,7 @@
  */
 using System;
 using System.IO;
+using System.Linq;
 using System.Text;
 using System.Collections;
 using FlickrNet;
@@ -22,7 +23,7 @@
 
 namespace FSpot.Exporters.Flickr {
 public class FlickrRemote {
-	public static Licenses    licenses;
+	public static LicenseCollection    licenses;
 	private string            frob;
 	private string            token;
 	private Auth              auth;
@@ -62,28 +63,29 @@
 		get { return flickr; }
 	}
 
-	public License[] GetLicenses ()
+	public LicenseCollection GetLicenses ()
 	{
 		// Licenses won't change normally in a user session
 		if (licenses == null) {
 			try {
 				licenses = flickr.PhotosLicensesGetInfo();
 			} catch (FlickrNet.FlickrApiException e ) {
-				Log.Error (e.Code + ": " + e.Verbose );
+				Log.Error (e.Code + ": " + e.Message );
 				return null;
 			}
 		}
-		return licenses.LicenseCollection;
+		return licenses;
 	}
 
 	public ArrayList Search (string[] tags, int licenseId)
 	{
+		var options = new PhotoSearchOptions { Tags = tags.Aggregate((a, b) => a + " " + b) };
 		ArrayList photos_url = new ArrayList ();
 		// Photos photos = flickr.PhotosSearchText (tags, licenseId);
-		Photos photos = flickr.PhotosSearch (tags);
+		PhotoCollection photos = flickr.PhotosSearch (options);
 
 		if (photos != null) {
-			foreach (FlickrNet.Photo photo in photos.PhotoCollection) {
+			foreach (FlickrNet.Photo photo in photos) {
 				photos_url.Add (photo.ThumbnailUrl);
 			}
 		}
@@ -93,11 +95,14 @@
 
 	public ArrayList Search (string tags, int licenseId)
 	{
+		var options = new PhotoSearchOptions{Tags = tags};
 		ArrayList photos_url = new ArrayList ();
-		Photos photos = flickr.PhotosSearchText (tags, licenseId);
+		// XXX: ignore license, probably should also set
+		// options.licenses
+		PhotoCollection photos = flickr.PhotosSearch (options);
 
 		if (photos != null) {
-			foreach (FlickrNet.Photo photo in photos.PhotoCollection) {
+			foreach (FlickrNet.Photo photo in photos) {
 				photos_url.Add (photo.ThumbnailUrl);
 			}
 		}
@@ -126,7 +131,7 @@
 
 				return auth;
 			} catch (FlickrNet.FlickrApiException ex) {
-				Log.Error ("Problems logging in to Flickr - " + ex.Verbose);
+				Log.Error ("Problems logging in to Flickr - " + ex.Message);
 				return null;
 			}
 		}
