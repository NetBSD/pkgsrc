# $NetBSD: Makefile,v 1.16 2015/02/15 14:45:48 ryoon Exp $

DISTNAME=	afio-2.5.1
CATEGORIES=	archivers
MASTER_SITES=	http://members.chello.nl/~k.holtman/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://members.chello.nl/~k.holtman/afio.html
COMMENT=	Data corruption handling cpio-format archive creator

BUILD_TARGET=	afio

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
# Don't define HAVE_LCHOWN
MAKE_FLAGS+=	e2=
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/afio ${DESTDIR}${PREFIX}/bin/afio
	${INSTALL_MAN} ${WRKSRC}/afio.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/afio.1

.include "../../mk/bsd.pkg.mk"
