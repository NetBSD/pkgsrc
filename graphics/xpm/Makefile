# $NetBSD: Makefile,v 1.33 2004/03/10 18:35:32 jlam Exp $

DISTNAME=       xpm-3.4k
PKGREVISION=	1
CATEGORIES=	graphics x11
MASTER_SITES=	http://koala.ilog.fr/ftp/pub/xpm/ \
		${MASTER_SITE_XCONTRIB:=libraries/}

MAINTAINER=	mycroft@NetBSD.org
HOMEPAGE=	http://www.inria.fr/koala/lehors/xpm.html
COMMENT=	The X Pixmap library

USE_BUILDLINK3=	# defined
USE_IMAKE=	# defined

CHECK_BUILTIN.xpm=	yes

.include "builtin.mk"

.if !empty(IS_BUILTIN.xpm:M[yY][eE][sS])
PKG_SKIP_REASON= "${PKGNAME} is part of your X11 distribution"
.endif

.if (${OPSYS} == SunOS)
post-install:
	cd ${PREFIX}/lib && \
	${RM} -f libXpm.so.4 && \
	${LN} -f libXpm.so.4.11 libXpm.so.4
.endif

.include "../../mk/bsd.pkg.mk"
