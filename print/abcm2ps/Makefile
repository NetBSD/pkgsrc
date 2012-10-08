# $NetBSD: Makefile,v 1.19 2012/10/08 13:45:34 asau Exp $

DISTNAME=	abcm2ps-6.6.6
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	http://moinejf.free.fr/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://moinejf.free.fr/
COMMENT=	Converts ABC to music sheet in PostScript format
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
BUILD_TARGET=	${PKGBASE}

USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--prefix=${DESTDIR}${PREFIX} \
			--docdir=${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
