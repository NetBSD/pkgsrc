# $NetBSD: Makefile,v 1.29 2023/12/15 13:48:12 wiz Exp $

DISTNAME=	generate-2.8
CATEGORIES=	devel
MASTER_SITES=	http://darcy.druid.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://darcy.druid.net/readme-generate.html
COMMENT=	Simple text pre-processor

CONFLICTS+=	glimmer-[0-9]*

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

MAKE_ENV+=	${BSD_MAKE_ENV} LIBS=${LIBS:Q}
USE_TOOLS+=	gmake
LIBS.SunOS=	-lsocket -lnsl
LIBS.QNX=	-lsocket

DIST_SUBDIR=	generate-20151222

BUILDLINK_TRANSFORM+=	rm:-Werror

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/generate ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rgenerate ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/generate.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/generate.1

.include "../../mk/bsd.pkg.mk"
