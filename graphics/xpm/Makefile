# $NetBSD: Makefile,v 1.25 2002/09/01 15:13:42 tron Exp $

DISTNAME=       xpm-3.4k
CATEGORIES=	graphics x11
MASTER_SITES=	http://koala.ilog.fr/ftp/pub/xpm/ \
		${MASTER_SITE_XCONTRIB:=libraries/}

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www.inria.fr/koala/lehors/xpm.html
COMMENT=	The X Pixmap library

USE_BUILDLINK2=	# defined
USE_IMAKE=	# defined

.include "../../mk/bsd.prefs.mk"

# Check if we got Xpm distributed with XFree86 4.x or Solaris 9.
.if (${OPSYS} != SunOS)
.if exists(${X11BASE}/include/X11/xpm.h) && \
    exists(${X11BASE}/lib/X11/config/X11.tmpl)
_IS_BUILTIN_XPM!=	${EGREP} -c NormalLibXpm ${X11BASE}/lib/X11/config/X11.tmpl || ${TRUE}
.else
_IS_BUILTIN_XPM=	0
.endif
.else
_IS_BUILTIN_XPM!=	(/usr/sbin/pkgchk -l SUNWxwinc | ${EGREP} -c xpm.h) || ${TRUE}
.endif

.if ${_IS_BUILTIN_XPM} != "0"
IGNORE=		"The Xpm library is included in your X11 distribution."
.endif

.if (${OPSYS} == SunOS)
post-install:
	cd ${PREFIX}/lib && \
	${RM} -f libXpm.so.4 && \
	${LN} -f libXpm.so.4.11 libXpm.so.4
.endif

.include "../../mk/bsd.pkg.mk"
