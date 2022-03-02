# $NetBSD: Makefile,v 1.19 2022/03/02 01:41:34 ryoon Exp $

DISTNAME=	algol68g-3.0.4
CATEGORIES=	lang
MASTER_SITES=	http://jmvdveer.home.xs4all.nl/

MAINTAINER=	olafs@cs.ru.nl
HOMEPAGE=	https://jmvdveer.home.xs4all.nl/algol.html
COMMENT=	Algol 68genie compiler
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${PREFIX}/share/doc/${PKGBASE}

SUBST_CLASSES+=		fix-path
SUBST_STAGE.fix-path=	pre-configure
SUBST_MESSAGE.fix-path=	Fixing /usr/local path.
SUBST_FILES.fix-path+=	Makefile.in
SUBST_SED.fix-path=	-e 's,/usr/local/include/algol68g,${PREFIX}/include/algol68g,g'

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Adding ${PREFIX}/include to compiler arguments.
SUBST_FILES.prefix+=	src/a68g/a68g.c
SUBST_VARS.prefix+=	PREFIX

TEST_TARGET=	check

.include "options.mk"

.include "../../mk/readline.buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
