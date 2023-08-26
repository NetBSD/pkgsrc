# $NetBSD: Makefile,v 1.25 2023/08/26 15:18:57 rhialto Exp $

DISTNAME=	algol68g-3.3.5
CATEGORIES=	lang
MASTER_SITES=	http://jmvdveer.home.xs4all.nl/

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://jmvdveer.home.xs4all.nl/en.algol-68-genie.html
COMMENT=	Algol 68genie compiler
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${PREFIX}/share/doc/${PKGBASE}

TEST_TARGET=	check

.include "options.mk"

.include "../../mk/readline.buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
