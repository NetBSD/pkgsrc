# $NetBSD: Makefile,v 1.14 2007/12/29 19:56:04 joerg Exp $

DISTNAME=		faad2-2.6.1
PKGNAME=		xmms-faad-2.6.1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=faac/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.audiocoding.com/
COMMENT=		XMMS plugin for faad

#RESTRICTED=		Dolby doesn't allow binary distributions
#NO_BIN_ON_FTP=		${RESTRICTED}
#NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=			${WRKDIR}/faad2
USE_TOOLS+=		automake gmake pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	# empty
DISTINFO_FILE=		${.CURDIR}/../../audio/faad2/distinfo
PATCHDIR=		${.CURDIR}/../../audio/faad2/patches

AUTOCONF_REQD=		2.50
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-xmms
CONFIGURE_ARGS+=	--with-mp4v2
BUILD_DIRS=		common/mp4ff plugins/xmms/src
INSTALL_DIRS=		plugins/xmms

pre-configure:
	${CP} ${WRKSRC}/common/faad/getopt.* ${WRKSRC}/frontend
	for dir in . ; do						\
		cd ${WRKSRC}/$$dir;					\
		aclocal -I .;						\
		autoheader;						\
		${LOCALBASE}/bin/libtoolize --automake;			\
		automake --add-missing;					\
		autoconf;						\
	done

.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
