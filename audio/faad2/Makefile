# $NetBSD: Makefile,v 1.46 2010/01/16 17:57:36 wiz Exp $

DISTNAME=	faad2-2.7
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=faac/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.audiocoding.com/
COMMENT=	AAC decoding library

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=	gnu-gpl-v2
RESTRICTED=	Dolby doesn't allow binary distributions
NO_BIN_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

USE_TOOLS+=	autoconf automake autoreconf gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES

AUTOCONF_REQD=	2.50
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/faad2

LIBS+=		-lm

CPPFLAGS.SunOS+=-D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE=1

post-extract:
	mv ${WRKSRC}/frontend/faad.man ${WRKSRC}/frontend/faad.1

pre-configure:
	cp ${WRKSRC}/common/faad/getopt.* ${WRKSRC}/frontend
	cd ${WRKSRC} && autoreconf -if

.include "../../mk/bsd.pkg.mk"
