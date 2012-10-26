$NetBSD: patch-include_xracer-player.h,v 1.1 2012/10/26 20:22:12 joerg Exp $

--- include/xracer-player.h.orig	2012-10-26 13:35:56.000000000 +0000
+++ include/xracer-player.h
@@ -130,79 +130,59 @@ extern void xrPlayerEndGame (void);
 extern void xrPlayerUpdate (const struct xrGameControls *controls);
 
 /* Inline structure accessors. */
-extern int xrPlayerHasExternalShield (const struct xrPlayer *player);
-
-extern inline int
+static inline int
 xrPlayerHasExternalShield (const struct xrPlayer *player)
 {
   return player->has_external_shield;
 }
 
-extern int xrPlayerHasAutoPilot (const struct xrPlayer *player);
-
-extern inline int
+static inline int
 xrPlayerHasAutoPilot (const struct xrPlayer *player)
 {
   return player->has_autopilot;
 }
 
 /* This always returns the position of the midpoint of the back line. */
-extern const GLfloat *xrPlayerGetPosition (const struct xrPlayer *player);
-
-extern inline const GLfloat *
+static inline const GLfloat *
 xrPlayerGetPosition (const struct xrPlayer *player)
 {
   return player->backline_midpoint;
 }
 
-extern int xrPlayerGetSegment (const struct xrPlayer *player);
-
-extern inline int
+static inline int
 xrPlayerGetSegment (const struct xrPlayer *player)
 {
   return player->seg[0];
 }
 
 /* Return the eye position, accounting for OOBE, if necessary. */
-extern const GLfloat *xrPlayerGetCameraEye (const struct xrPlayer *player,
-					    int oobe);
-
-extern inline const GLfloat *
+static inline const GLfloat *
 xrPlayerGetCameraEye (const struct xrPlayer *player, int oobe)
 {
   return oobe ? player->eye_oobe : player->backline_midpoint;
 }
 
 /* Return the camera centre point, accounting for OOBE, if necessary. */
-extern const GLfloat *xrPlayerGetCameraCentre (const struct xrPlayer *player,
-					       int oobe);
-
-extern inline const GLfloat *
+static inline const GLfloat *
 xrPlayerGetCameraCentre (const struct xrPlayer *player, int oobe)
 {
   return oobe ? player->centre_oobe : player->posn[0];
 }
 
 /* Return the camera up vector (this is unaffected by OOBE). */
-extern const GLfloat *xrPlayerGetCameraUp (const struct xrPlayer *player);
-
-extern inline const GLfloat *
+static inline const GLfloat *
 xrPlayerGetCameraUp (const struct xrPlayer *player)
 {
   return player->up;
 }
 
-extern int xrPlayerGetSpeed (const struct xrPlayer *player);
-
-extern inline int
+static inline int
 xrPlayerGetSpeed (const struct xrPlayer *player)
 {
   return xrMagnitude (player->momentum[0]) * 500.;
 }
 
-extern int xrPlayerGetPowerup (const struct xrPlayer *player);
-
-extern inline int
+static inline int
 xrPlayerGetPowerup (const struct xrPlayer *player)
 {
   return player->powerup;
@@ -211,18 +191,14 @@ xrPlayerGetPowerup (const struct xrPlaye
 /* Return the player's current lap, counting from 1. After the player has
  * completed the game, this can return NR_LAPS + 1, so beware.
  */
-extern int xrPlayerGetCurrentLap (const struct xrPlayer *player);
-
-extern inline int
+static inline int
 xrPlayerGetCurrentLap (const struct xrPlayer *player)
 {
   return player->displayed_current_lap + 1;
 }
 
 /* Return the player's current lap time. */
-extern double xrPlayerGetCurrentLapTime (const struct xrPlayer *player);
-
-extern inline double
+static inline double
 xrPlayerGetCurrentLapTime (const struct xrPlayer *player)
 {
   return xrCurrentTime - player->start_of_lap_time;
@@ -232,9 +208,7 @@ xrPlayerGetCurrentLapTime (const struct 
  * Note: the LAP argument starts counting from 1, and must be <= NR_LAPS.
  * This function does not return the current lap time.
  */
-extern double xrPlayerGetLapTime (const struct xrPlayer *player, int lap);
-
-extern inline double
+static inline double
 xrPlayerGetLapTime (const struct xrPlayer *player, int lap)
 {
   lap--;
