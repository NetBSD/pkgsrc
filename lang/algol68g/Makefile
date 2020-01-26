# $NetBSD: Makefile,v 1.15 2020/01/26 17:31:26 rillig Exp $

DISTNAME=	algol68g-2.8.3
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://jmvdveer.home.xs4all.nl/

MAINTAINER=	olafs@cs.ru.nl
HOMEPAGE=	https://jmvdveer.home.xs4all.nl/algol.html
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
