# $NetBSD: options.mk,v 1.6 2022/12/06 01:45:17 gutteridge Exp $

# print/lilypond and devel/py-game are optional because they pull in
# large and complex dependency chains. (lilypond also has a tendency
# to fail to build.)

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

# py-game is required for MIDI realtime playback.
.if !empty(PKG_OPTIONS:Mpy-game)
DEPENDS+=	${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game
.endif
