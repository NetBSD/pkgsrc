# $NetBSD: version.mk,v 1.3 2026/09/25 09:48:08 wiz Exp $

# The only thing that differs from the X11 build is which package to
# ask for.
.include "../../editors/emacs30/version.mk"

_EMACS_REQD=	emacs30-nox11>=30.1<31
