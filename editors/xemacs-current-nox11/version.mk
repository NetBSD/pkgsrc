# $NetBSD: version.mk,v 1.3 2026/09/25 09:48:09 wiz Exp $

# The only thing that differs from the X11 build is which package to
# ask for.
.include "../../editors/xemacs-current/version.mk"

_EMACS_REQD=		xemacs-nox11>=21.5<21.6
