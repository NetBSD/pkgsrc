# $NetBSD: x11-clients.buildlink3.mk,v 1.1 2005/05/09 13:01:29 xtraeme Exp $
#
# This Makefile fragment is meant to be used for packages requiring
# X11 applications like bdftopcf and so on, this Makefile is useless
# if you are using the X11 distribution that comes with your system,
# but it's useful if you use xorg or XFree86 from pkgsrc.

.if !defined(X11CLIENTS_BUILDLINK3_MK)
X11CLIENTS_BUILDLINK3_MK=       defined

.include "../../mk/bsd.prefs.mk"

X11CLIENTS_DEPMETHOD?=         build

# Require at least these versions for now.

XORG_DISTVER?=                  6.8.0
XFREE86_DISTVER?=               4.4.0

.if defined(X11_TYPE) && empty(X11_TYPE:Mnative)
.  if !empty(X11CLIENTS_DEPMETHOD:Mbuild)
.    if !empty(X11_TYPE:Mxorg)
BUILD_DEPENDS+=                 \
        xorg-clients>=${XORG_DISTVER}:../../x11/xorg-clients
.    elif !empty(X11_TYPE:MXFree86)
BUILD_DEPENDS+=                 \
        XFree86-clients>=${XFREE86_DISTVER}:../../x11/XFree86-clients
.    endif
.  endif

.  if !empty(X11CLIENTS_DEPMETHOD:Mfull)
.    if !empty(X11_TYPE:Mxorg)
DEPENDS+=                       \
        xorg-clients>=${XORG_DISTVER}:../../x11/xorg-clients
.    elif !empty(X11_TYPE:MXFree86)
DEPENDS+=                       \
        XFree86-clients>=${XFREE86_DISTVER}:../../x11/XFree86-clients
.    endif
.  endif
.endif # X11_TYPE=native

.endif # X11CLIENTS_BUILDLINK3_MK
