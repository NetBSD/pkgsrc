# $NetBSD: Makefile,v 1.22 2001/08/22 17:38:59 jlam Exp $

DISTNAME=       xpm-3.4k
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://avahi.inria.fr/pub/xpm/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www.inria.fr/koala/lehors/xpm.html
COMMENT=	The X Pixmap library

USE_IMAKE=		# defined
CHECK_XPM=		# defined

.include "../../mk/bsd.prefs.mk"

.if ${HAVE_BUILTIN_XPM} != "NO"
IGNORE=		"The Xpm library is included in your X11 distribution."
.endif

.if (${OPSYS} == SunOS)
post-install:
	cd ${PREFIX}/lib && \
	${RM} -f libXpm.so.4 && \
	${LN} -f libXpm.so.4.11 libXpm.so.4
.endif

.include "../../mk/bsd.pkg.mk"
