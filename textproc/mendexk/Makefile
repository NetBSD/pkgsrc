# $NetBSD: Makefile,v 1.7 2015/04/25 10:03:52 markd Exp $

DISTNAME=	texlive-20140525-source
PKGNAME=	mendexk-2.6f
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2014/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Replacement for makeindex with many enhancements
LICENSE=	modified-bsd

CONFLICTS+=	ja-ptex-bin-[0-9]*

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/mendexk

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/mendexk

CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.sub

CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib \
		--with-system-ptexenc \
		--with-ptexenc-includes=${BUILDLINK_PREFIX.ptexenc}/include \
		--with-ptexenc-libdir=${BUILDLINK_PREFIX.ptexenc}/lib

.include "../../print/kpathsea/buildlink3.mk"
BUILDLINK_API_DEPENDS.ptexenc+= ptexenc>=1.3.2
.include "../../print/ptexenc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
