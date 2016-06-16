# $NetBSD: Makefile,v 1.4 2016/06/16 04:06:20 markd Exp $

DISTNAME=	texlive-20160523-source
PKGNAME=	tex4ht-0.0.20160522
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2016/
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
USE_TOOLS+=	perl:run pkg-config
REPLACE_PERL=	mk4ht.pl

CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.sub

CONFIGURE_ARGS+=	--with-system-kpathsea

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
