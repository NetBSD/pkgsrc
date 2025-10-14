# $NetBSD: options.mk,v 1.7 2025/10/14 03:21:50 gutteridge Exp $

# print/lilypond and devel/py-game are optional because they pull in
# large and complex dependency chains. py-game is required for MIDI
# realtime playback.

# audio/musescore is also an application dependency that gets called
# by music21's show() method, but it's a pretty heavy dependency for
# some edge functionality, so it's been left off here.

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-music21
PKG_SUPPORTED_OPTIONS=	lilypond py-game
PKG_SUGGESTED_OPTIONS=	py-game

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlilypond)
DEPENDS+=	lilypond-[0-9]*:../../print/lilypond
.endif

.if !empty(PKG_OPTIONS:Mpy-game)
DEPENDS+=	${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game
.endif
