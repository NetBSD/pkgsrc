# $NetBSD: Makefile,v 1.26 2013/10/08 11:25:55 darcy Exp $
#

DISTNAME=	generate-2.8
CATEGORIES=	devel
MASTER_SITES=	http://darcy.druid.net/
EXTRACT_SUFX=	.tgz

OWNER=		darcy@NetBSD.org
HOMEPAGE=	http://darcy.druid.net/readme-generate.html
COMMENT=	Simple text pre-processor

CONFLICTS+=	glimmer-[0-9]*

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

MAKE_ENV+=	${BSD_MAKE_ENV} LIBS=${LIBS:Q}
USE_TOOLS+=	gmake
LIBS.SunOS=	-lsocket -lnsl
LIBS.QNX=	-lsocket

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/generate ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rgenerate ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/generate.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/generate.1

.include "../../mk/bsd.pkg.mk"
