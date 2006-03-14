# $NetBSD: Makefile,v 1.44 2006/03/14 01:14:34 jlam Exp $

DISTNAME=	xcdroast-${DIST_VER}
PKGNAME=	xcdroast-${DIST_VER:S/alpha/a/}
PKGREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xcdroast/}

MAINTAINER=	frueauf@NetBSD.org
HOMEPAGE=	http://www.xcdroast.org/
COMMENT=	Graphical user interface for the command-line cdrecord-tools

BUILD_USES_MSGFMT=	YES

DEPENDS+=		cdrtools>=2.01:../../sysutils/cdrtools

DIST_VER=		0.98alpha15

USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-gtk2
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

.include "../../mk/bsd.prefs.mk"

.if ${_OPSYS_HAS_OSSAUDIO} == "yes"
CFLAGS+=	-DHAVE_OSS
CONFIGURE_ENV+=	AUDIO_LIBS=${LIBOSSAUDIO:Q}
.endif

DOCDIR=		${PREFIX}/share/doc/xcdroast
DOCFILES=	DOCUMENTATION FAQ README.nonroot manual/xcdroast-manual.pdf
HTMLDIR=	${PREFIX}/share/doc/html/xcdroast
CONF_FILES=	/dev/null ${PKG_SYSCONFDIR}/xcdroast.conf

pre-build:
	cd ${WRKSRC}/src; for file in io.c wavplay.c; do		\
		${SED} -e "s|@DEVOSSAUDIO@|${DEVOSSAUDIO}|g"		\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	(cd ${WRKSRC}/doc;						\
	for file in ${DOCFILES}; do	\
		${INSTALL_DATA} $${file} ${DOCDIR};			\
	done)

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
