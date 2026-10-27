# $NetBSD: Makefile,v 1.42 2026/10/27 13:53:22 adam Exp $

DISTNAME=	lowdown-3.2.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=kristapsdz/}
GITHUB_TAG=	VERSION_${PKGVERSION_NOREV:S/./_/g}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kristaps.bsd.lv/lowdown/
COMMENT=	Simple Markdown translator
LICENSE=	isc

WRKSRC=		${WRKDIR}/${PKGBASE}-${GITHUB_TAG:C/.*\///}

HAS_CONFIGURE=		yes

SUBST_CLASSES+=		install
SUBST_SED.install=	-e 's|/usr/local|${PREFIX}|'
SUBST_SED.install+=	-e 's|^MANDIR=.*|MANDIR=${PREFIX}/${PKGMANDIR}|'
SUBST_SED.install+=	-e '/^CC=.*/d'
SUBST_SED.install+=	-e '/^CFLAGS=.*/d'
SUBST_SED.install+=	-e '/^LDFLAGS=.*/d'
SUBST_FILES.install+=	configure
SUBST_STAGE.install=	pre-configure
SUBST_MESSAGE.install=	Fixing installation path.

INSTALL_TARGET=		install install_libs
TEST_TARGET=		regress

pre-configure:
	${ECHO} HAVE_SANDBOX_INIT=0 >> ${WRKSRC}/configure.local

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
post-install: fix-darwin-install-name
.PHONY: fix-darwin-install-name
fix-darwin-install-name:
	install_name_tool -id ${PREFIX}/lib/liblowdown.5.dylib \
		${DESTDIR}${PREFIX}/lib/liblowdown.5.dylib
.endif

.include "../../mk/bsd.pkg.mk"
