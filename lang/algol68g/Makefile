# $NetBSD: Makefile,v 1.29 2024/10/05 15:51:02 rhialto Exp $

DISTNAME=	algol68g-3.5.5
CATEGORIES=	lang
MASTER_SITES=	http://jmvdveer.home.xs4all.nl/

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://jmvdveer.home.xs4all.nl/en.algol-68-genie.html
COMMENT=	Algol 68genie compiler
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c
USE_CC_FEATURES=	c17
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/${PKGBASE}
CONFIGURE_ARGS+=	--enable-compiler
CONFIGURE_ARGS+=	--enable-parallel
CONFIGURE_ARGS+=	--enable-curl
CONFIGURE_ARGS+=	--enable-curses
CONFIGURE_ARGS+=	--enable-gsl
CONFIGURE_ARGS+=	--enable-readline
CONFIGURE_ARGS+=	--disable-mathlib	# no -lRmath

SUBST_CLASSES+=		pkg
SUBST_STAGE.pkg=	pre-configure
SUBST_FILES.pkg=	configure
SUBST_VARS.pkg=		PREFIX

TEST_TARGET=		check

.include "options.mk"

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
