# $NetBSD: Makefile,v 1.36 2017/02/06 13:55:52 wiz Exp $

DISTNAME=	abcm2ps-8.13.4
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://moinejf.free.fr/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://moinejf.free.fr/
COMMENT=	Converts ABC to music sheet in PostScript format
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
BUILD_TARGET=	abcm2ps

CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc

.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
