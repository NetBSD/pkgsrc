# $NetBSD: x11.buildlink2.mk,v 1.4.2.2 2003/06/12 15:27:10 jschauma Exp $
#
# This file is for internal use by bsd.buildlink2.mk and should _not_ be
# include by package Makefiles.

.if !defined(X11_BUILDLINK2_MK)
X11_BUILDLINK2_MK=	# defined

USE_X11?=	# defined
USE_X11_LINKS=	no

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "IRIX"
.  include "../../pkgtools/x11-links/xsgi.buildlink2.mk"
.else
.  if !empty(X11BASE:M*openwin)
.    include "../../pkgtools/x11-links/openwin.buildlink2.mk"
.  else
.    include "../../pkgtools/x11-links/xfree.buildlink2.mk"
.  endif
.endif

.endif	# X11_BUILDLINK2_MK
