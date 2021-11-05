# $NetBSD: Makefile,v 1.25 2021/11/05 11:06:24 fcambus Exp $

DISTNAME=	lowdown-0.10.0
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

TEST_TARGET=	regress

.include "../../mk/bsd.pkg.mk"
