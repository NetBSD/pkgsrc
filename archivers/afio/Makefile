# $NetBSD: Makefile,v 1.20 2025/11/19 08:27:58 wiz Exp $

DISTNAME=	afio-2.5.2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=kholtman/}
GITHUB_PROJECT=	afio
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kholtman/afio
COMMENT=	Data corruption handling cpio-format archive creator

BUILD_TARGET=	afio

# Don't define HAVE_LCHOWN
MAKE_FLAGS.Darwin+=	e2=

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/afio ${DESTDIR}${PREFIX}/bin/afio
	${INSTALL_MAN} ${WRKSRC}/afio.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/afio.1

.include "../../mk/bsd.pkg.mk"
