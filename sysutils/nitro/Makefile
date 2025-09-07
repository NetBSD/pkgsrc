# $NetBSD: Makefile,v 1.1 2025/09/07 09:36:35 imil Exp $

DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-0.3.0.0.20250907
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=leahneukirchen/}
GITHUB_PROJECT=	nitro
GITHUB_TAG=	9507f103b43094261e5bd7aa8dcd7f03ea6036d6

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/leahneukirchen/nitro
COMMENT=	Tiny but flexible init system and process supervisor
LICENSE=	0-clause-bsd

BUILD_DEFS+=	VARBASE

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_SED.prefix=	-e 's|/etc|${PREFIX}/etc|g'
SUBST_SED.prefix+=	-e 's|/var|${VARBASE}|g'
SUBST_FILES.prefix=	nitro.h nitro.c nitroctl.c nitro.8 README.md

OWN_DIRS+=	${VARBASE}/run/nitro
OWN_DIRS+=	${PKG_SYSCONFDIR}/nitro

PLIST_SUBST+=	SRC_SOCK=${VARBASE}/run/nitro/nitro.sock \
		DST_SOCK=${PKG_SYSCONFDIR}/nitro.sock

INSTALLATION_DIRS=	bin sbin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8 etc share/doc/nitro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nitro ${DESTDIR}${PREFIX}/sbin/nitro
	${INSTALL_PROGRAM} ${WRKSRC}/nitroctl ${DESTDIR}${PREFIX}/bin/nitroctl
	${INSTALL_MAN} ${WRKSRC}/nitro.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/nitro.8
	${INSTALL_MAN} ${WRKSRC}/halt.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/halt.8
	${INSTALL_MAN} ${WRKSRC}/nitroctl.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nitroctl.1
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/nitro/README.md

.include "../../mk/bsd.pkg.mk"
