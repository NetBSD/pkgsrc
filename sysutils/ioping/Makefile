# $NetBSD: Makefile,v 1.4 2022/03/26 13:06:58 wiz Exp $

DISTNAME=	ioping-1.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=koct9i/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	miwarin@gmail.com
HOMEPAGE=	https://github.com/koct9i/ioping/
COMMENT=	Monitor I/O latency in real time
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ioping ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ioping.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
