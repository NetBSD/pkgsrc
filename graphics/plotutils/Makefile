# $NetBSD: Makefile,v 1.53 2020/01/18 23:32:17 rillig Exp $

DISTNAME=	plotutils-2.6
PKGREVISION=	4
CATEGORIES=	devel graphics
MASTER_SITES=	${MASTER_SITE_GNU:=plotutils/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/plotutils/plotutils.html
COMMENT=	Programs and library for plotting scientific data
LICENSE=	gnu-gpl-v3

CONFLICTS+=	plotutils-nox11-[0-9]*

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		lex:run yacc
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libplotter
MAKE_JOBS_SAFE=		no
INFO_FILES=		yes

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
