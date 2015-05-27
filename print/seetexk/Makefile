# $NetBSD: Makefile,v 1.1 2015/05/27 22:13:15 markd Exp $

DISTNAME=	texlive-20140525-source
PKGNAME=	seetexk-1.1
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2014/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Utilities for manipulating DVI files
LICENSE=	x11

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/seetexk

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/seetexk

CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.sub

CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib

.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
