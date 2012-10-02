# $NetBSD: Makefile,v 1.5 2012/10/02 20:11:35 asau Exp $
#

DISTNAME=	algol68g-2.4.1
CATEGORIES=	lang
MASTER_SITES=	http://jmvdveer.home.xs4all.nl/

MAINTAINER=	olafs@cs.ru.nl
HOMEPAGE=	http://jmvdveer.home.xs4all.nl/algol.html
COMMENT=	Algol 68genie compiler
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=$(PREFIX)/share/doc/$(PKGBASE)
# Since it ignores configure flag currently, override it through make argument,
# this should be fixed in 2.4.2:
INSTALL_MAKE_FLAGS=	docdir=$(PREFIX)/share/doc/$(PKGBASE)

TEST_TARGET=	check

.include "options.mk"

.include "../../devel/readline/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
