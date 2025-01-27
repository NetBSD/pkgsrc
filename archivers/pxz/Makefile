# $NetBSD: Makefile,v 1.2 2025/01/27 19:12:38 rillig Exp $

DISTNAME=	pxz-4.999.9beta
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=jnovy/}
GITHUB_PROJECT=	pxz
GITHUB_TAG=	124382a6d0832b13b7c091f72264f8f3f463070a

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
