# $NetBSD: Makefile,v 1.23 2001/08/30 11:11:24 wiz Exp $

DISTNAME=       xpm-3.4k
CATEGORIES=	graphics x11
MASTER_SITES=	http://koala.ilog.fr/ftp/pub/xpm/ \
		${MASTER_SITE_XCONTRIB:=libraries/}

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
