# $NetBSD: Makefile,v 1.44 2005/08/11 22:46:05 dmcmahill Exp $

DISTNAME=       xpm-3.4k
PKGREVISION=	5
CATEGORIES=	graphics x11
MASTER_SITES=	http://koala.ilog.fr/ftp/pub/xpm/ \
		${MASTER_SITE_XCONTRIB:=libraries/}

MAINTAINER=	mycroft@NetBSD.org
HOMEPAGE=	http://www.inria.fr/koala/lehors/xpm.html
COMMENT=	The X Pixmap library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_IMAKE=	# defined

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
post-install:
	cd ${PREFIX}/lib && \
	${RM} -f libXpm.so.4 && \
	${LN} -f libXpm.so.4.11 libXpm.so.4
.endif

.include "../../mk/bsd.pkg.mk"
