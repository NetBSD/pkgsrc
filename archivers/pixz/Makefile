# $NetBSD: Makefile,v 1.1 2021/04/13 03:09:01 ryoon Exp $
#

GITHUB_PROJECT=	pixz
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
DISTNAME=	pixz-1.0.7
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=vasi/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/vasi/pixz
COMMENT=	Parallel, indexed xz compressor
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/src/pixz.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1


.include "../../archivers/libarchive/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
