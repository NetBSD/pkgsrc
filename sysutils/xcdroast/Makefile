# $NetBSD: Makefile,v 1.37 2005/12/05 20:51:02 rillig Exp $

DISTNAME=	xcdroast-0.98alpha15
PKGNAME=	xcdroast-0.98a15
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xcdroast/}

MAINTAINER=	frueauf@NetBSD.org
HOMEPAGE=	http://www.xcdroast.org/
COMMENT=	Graphical user interface for the command-line cdrecord-tools

BUILD_USES_MSGFMT=	YES

DEPENDS+=		cdrecord-xcdroast-0.98a15.*:../../sysutils/cdrecord-xcdroast

USE_TOOLS+=		gmake pkg-config
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-gtk2
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"

.if ${_OPSYS_HAS_OSSAUDIO} == "yes"
CFLAGS+=	-DHAVE_OSS
CONFIGURE_ENV+=	AUDIO_LIBS=${LIBOSSAUDIO:Q}
.endif

DOCDIR=		${PREFIX}/share/doc/xcdroast
DOCFILES=	DOCUMENTATION FAQ README.nonroot manual/xcdroast-manual.pdf
HTMLDIR=	${PREFIX}/share/doc/html/xcdroast
CONF_FILES=	/dev/null ${PKG_SYSCONFDIR}/xcdroast.conf

INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

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
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
