# $NetBSD: Makefile,v 1.23.2.2 2002/06/21 23:05:26 jlam Exp $

DISTNAME=       xpm-3.4k
CATEGORIES=	graphics x11
MASTER_SITES=	http://koala.ilog.fr/ftp/pub/xpm/ \
		${MASTER_SITE_XCONTRIB:=libraries/}

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www.inria.fr/koala/lehors/xpm.html
COMMENT=	The X Pixmap library

USE_BUILDLINK2=	# defined
USE_IMAKE=	# defined
CHECK_XPM=	# defined

.include "../../mk/bsd.prefs.mk"

.if ${HAVE_BUILTIN_XPM} != "NO"
#IGNORE=		"The Xpm library is included in your X11 distribution."
.endif

.if (${OPSYS} == SunOS)
post-install:
	cd ${PREFIX}/lib && \
	${RM} -f libXpm.so.4 && \
	${LN} -f libXpm.so.4.11 libXpm.so.4
.endif

.include "../../mk/bsd.pkg.mk"
