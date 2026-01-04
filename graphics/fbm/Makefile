# $NetBSD: Makefile,v 1.14 2026/01/04 09:48:56 wiz Exp $

DISTNAME=	fbm-1.2
CATEGORIES=	graphics converters
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/graphics/convert/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fuzzy Pixmap Manipulation utilities

WRKSRC=			${WRKDIR}
INSTALL_MAKE_FLAGS+=	BIN=${DESTDIR}${PREFIX}/bin/ \
			MAN=${DESTDIR}${PREFIX}/${PKGMANDIR}/manl/
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/manl

CFLAGS+=	-Wno-implicit-function-declaration
CFLAGS+=	-Wno-implicit-int

.include "../../mk/bsd.pkg.mk"
