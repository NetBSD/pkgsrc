# $NetBSD: x11.buildlink2.mk,v 1.3 2002/10/22 22:54:08 jlam Exp $
#
# This file is for internal use by bsd.buildlink2.mk and should _not_ be
# include by package Makefiles.

.if !defined(X11_BUILDLINK2_MK)
X11_BUILDLINK2_MK=	# defined

USE_X11?=	# defined
USE_X11_LINKS=	no

.include "../../mk/bsd.prefs.mk"

.if !empty(X11BASE:M*openwin)
.  include "../../pkgtools/x11-links/openwin.buildlink2.mk"
.else
.  include "../../pkgtools/x11-links/xfree.buildlink2.mk"
.endif

.endif	# X11_BUILDLINK2_MK
