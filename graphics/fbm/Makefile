# $NetBSD: Makefile,v 1.11 2010/02/03 23:24:54 joerg Exp $

DISTNAME=	fbm-1.2
CATEGORIES=	graphics converters
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/graphics/convert/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fuzzy Pixmap Manipulation utilities

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
INSTALL_MAKE_FLAGS+=	BIN=${DESTDIR}${PREFIX}/bin/ \
			MAN=${DESTDIR}${PREFIX}/${PKGMANDIR}/manl/
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/manl

.include "../../mk/bsd.pkg.mk"
