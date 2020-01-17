# $NetBSD: options.mk,v 1.1 2020/01/17 05:41:44 gutteridge Exp $

# audio/musescore is also an application dependency that gets called
# by music21's show() method, but it's a pretty heavy dependency for
# some edge functionality, so it's been left off here.

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-music21
PKG_SUPPORTED_OPTIONS=	lilypond
PKG_SUGGESTED_OPTIONS=	lilypond

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlilypond)
DEPENDS+=	lilypond-[0-9]*:../../print/lilypond
.endif
