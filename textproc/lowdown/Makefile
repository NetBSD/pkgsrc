# $NetBSD: Makefile,v 1.12 2020/07/28 20:57:59 fcambus Exp $

DISTNAME=	lowdown-0.7.2
CATEGORIES=	textproc
MASTER_SITES=	https://kristaps.bsd.lv/lowdown/snapshots/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
