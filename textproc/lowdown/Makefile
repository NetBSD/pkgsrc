# $NetBSD: Makefile,v 1.33 2023/05/26 20:38:47 schmonz Exp $

DISTNAME=		lowdown-1.0.2
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=kristapsdz/}
GITHUB_TAG=		refs/tags/VERSION_${PKGVERSION_NOREV:S/./_/g}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://kristaps.bsd.lv/lowdown/
COMMENT=		Simple Markdown translator
LICENSE=		isc

WRKSRC=			${WRKDIR}/${PKGBASE}-${GITHUB_TAG:C/.*\///}

HAS_CONFIGURE=		yes
USE_LIBTOOL=		yes

SUBST_CLASSES+=		install
SUBST_SED.install=	-e 's|/usr/local|${PREFIX}|'
SUBST_SED.install+=	-e 's|^MANDIR=.*|MANDIR=${PREFIX}/${PKGMANDIR}|'
SUBST_SED.install+=	-e '/^CC=.*/d'
SUBST_SED.install+=	-e '/^CFLAGS=.*/d'
SUBST_SED.install+=	-e '/^LDFLAGS=.*/d'
SUBST_FILES.install+=	configure
SUBST_STAGE.install=	pre-configure
SUBST_MESSAGE.install=	Fixing installation path.

INSTALL_TARGET=		install install_pkgsrc

TEST_TARGET=		regress

pre-configure:
	${ECHO} HAVE_SANDBOX_INIT=0 >> ${WRKSRC}/configure.local

.include "../../mk/bsd.pkg.mk"
