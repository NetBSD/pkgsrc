# $NetBSD: Makefile,v 1.1 2021/04/16 16:16:05 ryoon Exp $

GITHUB_PROJECT=	pxz
GITHUB_TAG=	124382a6d0832b13b7c091f72264f8f3f463070a
DISTNAME=	pxz-4.999.9beta
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=jnovy/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://jnovy.fedorapeople.org/pxz/
COMMENT=	Parallel LZMA compressor using liblzma
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pxz ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pxz.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../archivers/xz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
