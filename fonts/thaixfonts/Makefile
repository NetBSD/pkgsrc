# $NetBSD: Makefile,v 1.12 2017/09/06 09:03:01 wiz Exp $
#

DISTNAME=	thaixfonts-1.2.7
CATEGORIES=	fonts x11
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/thaixfonts/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://linux.thai.net/projects/thaixfonts
COMMENT=	The collection of Thai X fonts

USE_TOOLS+=	gmake bdftopcf gzip
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-fontdir=${FONTDIR}

FONTDIR=		${PREFIX}/share/fonts/X11/thaixfonts
FONTS_DIRS.x11+=	${FONTDIR}
INSTALLATION_DIRS=		${FONTDIR}

post-install:
	cp -p ${DESTDIR}${FONTDIR}/thai.alias ${DESTDIR}${FONTDIR}/fonts.alias

.include "../../mk/bsd.pkg.mk"
