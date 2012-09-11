# $NetBSD: Makefile,v 1.12 2012/09/11 19:46:52 asau Exp $

DISTNAME=	afio-2.5
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/system/backup/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freshmeat.net/projects/afio/
COMMENT=	cpio-format archive creator with data corruption handling

PKG_INSTALLATION_TYPES=	overwrite pkgviews

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
