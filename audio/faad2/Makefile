# $NetBSD: Makefile,v 1.40.8.1 2008/09/26 14:42:13 tron Exp $

DISTNAME=	faad2-2.6.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=faac/}
PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.audiocoding.com/
COMMENT=	AAC decoding library

PKG_DESTDIR_SUPPORT=	user-destdir

RESTRICTED=	Dolby doesn't allow binary distributions
NO_BIN_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

WRKSRC=		${WRKDIR}/faad2
USE_TOOLS+=	automake gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES

AUTOCONF_REQD=	2.50
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/faad2
# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE:Q}

LIBS+=		-lm

CPPFLAGS.SunOS+=-D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE=1

pre-configure:
	@${CP} ${WRKSRC}/common/faad/getopt.* ${WRKSRC}/frontend
	for dir in . ; do						\
		cd ${WRKSRC}/$$dir;					\
		aclocal -I .;						\
		autoheader;						\
		${LOCALBASE}/bin/libtoolize --automake;			\
		automake --add-missing;					\
		autoconf;						\
	done

.include "../../mk/bsd.pkg.mk"
