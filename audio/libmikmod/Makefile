# $NetBSD: Makefile,v 1.58 2014/10/09 14:05:56 wiz Exp $

DISTNAME=	libmikmod-3.3.6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mikmod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mikmod.sourceforge.net/
COMMENT=	MikMod Sound Library
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=		autoconf gmake makeinfo
USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-threads

INFO_FILES=		yes
PKGCONFIG_OVERRIDE=	libmikmod.pc.in

pre-configure:
	cd ${WRKSRC} && autoconf

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
