# $NetBSD: Makefile,v 1.8 2012/10/03 18:28:31 asau Exp $
#

DISTNAME=	thaixfonts-1.2.5
CATEGORIES=	fonts x11
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/thaixfonts/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linux.thai.net/projects/thaixfonts
COMMENT=	The collection of Thai X fonts

USE_TOOLS+=	gmake bdftopcf gzip
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-fontdir=${FONTDIR}

FONTDIR=		${PREFIX}/lib/X11/fonts/thaixfonts
FONTS_DIRS.x11+=	${FONTDIR}
INSTALLATION_DIRS=		${FONTDIR}

post-install:
	cp -p ${DESTDIR}${FONTDIR}/thai.alias ${DESTDIR}${FONTDIR}/fonts.alias

.include "../../mk/bsd.pkg.mk"
