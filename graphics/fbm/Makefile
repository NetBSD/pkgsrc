# $NetBSD: Makefile,v 1.12 2012/10/06 14:10:48 asau Exp $

DISTNAME=	fbm-1.2
CATEGORIES=	graphics converters
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/graphics/convert/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fuzzy Pixmap Manipulation utilities

WRKSRC=		${WRKDIR}
INSTALL_MAKE_FLAGS+=	BIN=${DESTDIR}${PREFIX}/bin/ \
			MAN=${DESTDIR}${PREFIX}/${PKGMANDIR}/manl/
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/manl

.include "../../mk/bsd.pkg.mk"
