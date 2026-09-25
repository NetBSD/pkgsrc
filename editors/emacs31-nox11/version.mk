# $NetBSD: version.mk,v 1.2 2026/09/25 09:48:08 wiz Exp $

# The only thing that differs from the X11 build is which package to
# ask for.
.include "../../editors/emacs31/version.mk"

_EMACS_REQD=	emacs31-nox11>=31.1<32
