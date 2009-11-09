# $NetBSD: Makefile,v 1.7 2009/11/09 14:36:15 joerg Exp $

DISTNAME=	jpegoptim-1.2.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.kokkonen.net/tjko/src/

MAINTAINER=	fab@gnux.info
HOMEPAGE=	http://www.kokkonen.net/tjko/projects.html
COMMENT=	JPEG optimizer

PKG_DESTDIR_SUPPORT=	user-destdir
GNU_CONFIGURE=		YES

INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
