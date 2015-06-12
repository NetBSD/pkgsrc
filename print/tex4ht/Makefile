# $NetBSD: Makefile,v 1.2 2015/06/12 10:51:00 wiz Exp $

DISTNAME=	texlive-20140525-source
PKGNAME=	tex4ht-0.0.20120725.1936
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2014/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Converter from *TeX to HTML, XML, and similar formats
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-bin<=3.0nb32

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/tex4htk

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/tex4htk
USE_TOOLS+=	perl:run
REPLACE_PERL=	mk4ht.pl

CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.sub

CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib

.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
