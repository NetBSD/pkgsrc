# $NetBSD: Makefile,v 1.32 2023/05/26 18:03:31 schmonz Exp $

DISTNAME=		lowdown-1.0.0
CATEGORIES=		textproc
MASTER_SITES=		https://kristaps.bsd.lv/lowdown/snapshots/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://kristaps.bsd.lv/lowdown/
COMMENT=		Simple Markdown translator
LICENSE=		isc

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

.include "../../mk/bsd.pkg.mk"
