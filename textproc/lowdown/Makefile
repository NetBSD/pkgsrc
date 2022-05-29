# $NetBSD: Makefile,v 1.29 2022/05/29 15:54:09 fcambus Exp $

DISTNAME=	lowdown-1.0.0
CATEGORIES=	textproc
MASTER_SITES=	https://kristaps.bsd.lv/lowdown/snapshots/

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://kristaps.bsd.lv/lowdown/
COMMENT=	Simple Markdown translator
LICENSE=	isc

HAS_CONFIGURE=	yes

SUBST_CLASSES+=		install
SUBST_SED.install+=	-e 's,/usr/local,${PREFIX},' \
			-e 's,^MANDIR=.*,MANDIR=${PREFIX}/${PKGMANDIR},' \
			-e '/^CC=.*/d'						\
			-e '/^CFLAGS=.*/d'					\
			-e '/^LDFLAGS=.*/d'
SUBST_FILES.install+=	configure
SUBST_STAGE.install=	pre-configure
SUBST_MESSAGE.install=	Fixing installation path.

INSTALL_TARGET=		install install_libs

TEST_TARGET=	regress

.include "../../mk/bsd.pkg.mk"
