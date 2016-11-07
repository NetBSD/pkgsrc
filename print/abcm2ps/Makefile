# $NetBSD: Makefile,v 1.32 2016/11/07 11:51:47 wiz Exp $

DISTNAME=	abcm2ps-8.12.9
CATEGORIES=	print
MASTER_SITES=	http://moinejf.free.fr/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://moinejf.free.fr/
COMMENT=	Converts ABC to music sheet in PostScript format
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
BUILD_TARGET=	abcm2ps

USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc

.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
