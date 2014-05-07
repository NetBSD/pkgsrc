# $NetBSD: Makefile,v 1.50 2014/05/07 10:34:30 jperkin Exp $

DISTNAME=	plotutils-2.6
PKGREVISION=	4
CATEGORIES=	devel graphics
MASTER_SITES=	${MASTER_SITE_GNU:=plotutils/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/plotutils/plotutils.html
COMMENT=	Programs and library for plotting scientific data
LICENSE=	gnu-gpl-v3

CONFLICTS+=	plotutils-nox11-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		lex yacc
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libplotter
MAKE_JOBS_SAFE=		no
INFO_FILES=		yes

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
