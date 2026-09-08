$NetBSD: patch-src_zenicb-stamp.el,v 1.1 2026/09/08 09:35:08 wiz Exp $

declare dynamic binding, not lexical binding
string-to-int has been replaced with string-to-number

--- src/zenicb-stamp.el.orig	1998-03-28 00:56:12.000000000 +0000
+++ src/zenicb-stamp.el
@@ -1,3 +1,5 @@
+;;; -*- lexical-binding: nil -*-
+
 ;;; zenicb-stamp.el --- timestamping for ZenICB
 
 ;; Copyright (C) 1998 Faried Nawaz
@@ -72,11 +74,11 @@ Written by Stephen Ma <ma_s@maths.su.oz.au>"
                   (let ((prodh (* num1 (car num2))) 
                         (prodl (* num1 (car (cdr num2)))))
                     (list (+ prodh (/ prodl 65536)) (% prodl 65536)))))
-         (seconds (string-to-int (substring timestr 17 19)))  
-         (minutes (string-to-int (substring timestr 14 16)))
-         (hours (string-to-int (substring timestr 11 13)))
-         (partdays (1- (string-to-int (substring timestr 8 10))))       
-         (years (string-to-int (substring timestr 20 24)))
+         (seconds (string-to-number (substring timestr 17 19)))  
+         (minutes (string-to-number (substring timestr 14 16)))
+         (hours (string-to-number (substring timestr 11 13)))
+         (partdays (1- (string-to-number (substring timestr 8 10))))       
+         (years (string-to-number (substring timestr 20 24)))
          (days (+ partdays
                   (cond ((and (= (% years 4) 0)
                               (/= (% years 100) 0))
@@ -147,14 +149,14 @@ the second argument to be earlier in time than the fir
   (save-match-data
     (let (millions units high low)    
       (if (string-match "^\\(.*\\)\\(......\\)$" seconds)
-          (setq millions (string-to-int (substring seconds
+          (setq millions (string-to-number (substring seconds
                                                    (match-beginning 1)  
                                                    (match-end 1)))      
-                units (string-to-int (substring seconds
+                units (string-to-number (substring seconds
                                                 (match-beginning 2)     
                                                 (match-end 2))))
         (setq millions 0
-              units (string-to-int seconds)))
+              units (string-to-number seconds)))
       (setq high (+ (* millions 15) (/ (* millions 265) 1024) (/ units 65536)) 
             low (+ (% (+ (* (% millions 4) 16384) (* millions 576)) 65536)
                    (% units 65536))) 
@@ -187,4 +189,4 @@ process PROC every zenicb-timestamp-interval seconds."
 (zenicb-add-hook 'zenicb-timer-hook 'zenicb-timestamp)
 (setq zenicb-time-last-event (zenicb-time-to-int (current-time-string)))
 
-(provide 'zenicb-stamp)
\ No newline at end of file
+(provide 'zenicb-stamp)
