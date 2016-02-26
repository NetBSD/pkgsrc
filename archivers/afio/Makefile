# $NetBSD: Makefile,v 1.18 2016/02/26 11:40:29 jperkin Exp $

DISTNAME=	afio-2.5.1
CATEGORIES=	archivers
MASTER_SITES=	http://members.chello.nl/~k.holtman/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://members.chello.nl/~k.holtman/afio.html
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
