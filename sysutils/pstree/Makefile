# $NetBSD: Makefile,v 1.31 2024/11/17 10:14:53 adam Exp $

DISTNAME=	pstree-2.40
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=FredHucht/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/FredHucht/pstree
COMMENT=	Display processes in a tree
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -o pstree pstree.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pstree ${DESTDIR}${PREFIX}/bin/proctree
	${INSTALL_MAN} ${WRKSRC}/pstree.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/proctree.1

.include "../../mk/bsd.pkg.mk"
