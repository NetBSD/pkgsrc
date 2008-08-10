# $NetBSD: Makefile,v 1.5 2008/08/10 09:47:05 obache Exp $
#

DISTNAME=	thaixfonts-1.2.4
CATEGORIES=	fonts x11
MASTER_SITES=	http://linux.thai.net/pub/thailinux/software/thaixfonts/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linux.thai.net/projects/thaixfonts
COMMENT=	The collection of Thai X fonts

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=	yes
USE_TOOLS+=	automake gmake bdftopcf gzip mkfontdir
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-fontdir=${FONTDIR}

FONTDIR=		${PREFIX}/lib/X11/fonts/thaixfonts
FONTS_DIRS.x11+=        ${FONTDIR}
OWN_DIRS=		${FONTDIR}

pre-configure:
		cd ${WRKSRC} && sh autogen.sh

.include "../../mk/bsd.pkg.mk"
