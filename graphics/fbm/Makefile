# $NetBSD: Makefile,v 1.13 2019/11/02 22:37:56 rillig Exp $

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

.include "../../mk/bsd.pkg.mk"
