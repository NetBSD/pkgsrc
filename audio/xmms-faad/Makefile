# $NetBSD: Makefile,v 1.1.1.1 2005/05/21 03:16:23 grant Exp $

DISTNAME=		faad2-2.0
PKGNAME=		xmms-faad-2.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=faac/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.audiocoding.com/
COMMENT=		XMMS plugin for faad

#RESTRICTED=		Dolby doesn't allow binary distributions
#NO_BIN_ON_FTP=		${RESTRICTED}
#NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=			${WRKDIR}/faad2
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	libtool

AUTOMAKE_REQD=		1.4
AUTOCONF_REQD=		2.50
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-xmms
CONFIGURE_ARGS+=	--with-mp4v2

.include "../../mk/bsd.prefs.mk"

pre-configure:
	@${CP} ${WRKSRC}/common/faad/getopt.* ${WRKSRC}/frontend
	for dir in . ; do						\
		cd ${WRKSRC}/$$dir;					\
		${ACLOCAL} -I .;					\
		${AUTOHEADER};						\
		${LOCALBASE}/bin/libtoolize --automake;			\
		${AUTOMAKE} --add-missing;				\
		${AUTOCONF};						\
	done

do-build:
	@cd ${WRKSRC}/plugins/xmms/src && \
		${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_TARGET}

do-install:
	@cd ${WRKSRC}/plugins/xmms && \
		${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
