# $NetBSD: Makefile,v 1.21 2003/12/28 19:34:43 jmmv Exp $

DISTNAME=	xcdroast-0.98alpha15
PKGNAME=	xcdroast-0.98a15
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xcdroast/}

MAINTAINER=	frueauf@NetBSD.org
HOMEPAGE=	http://www.xcdroast.org/
COMMENT=	Graphical user interface for the command-line cdrecord-tools

BUILD_USES_MSGFMT=	YES

DEPENDS+=		cdrecord-xcdroast-0.98a15.*:../cdrecord-xcdroast

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-gtk2
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"

.if ${_OPSYS_HAS_OSSAUDIO} == "yes"
CFLAGS+=	-DHAVE_OSS
AUDIO_LIBS=	-lossaudio
CONFIGURE_ENV+=	AUDIO_LIBS=${AUDIO_LIBS}
.endif

DOCDIR=		${PREFIX}/share/doc/xcdroast
DOCFILES=	DOCUMENTATION FAQ README.nonroot manual/xcdroast-manual.pdf
HTMLDIR=	${PREFIX}/share/doc/html/xcdroast
SUPPORT_FILES=	/dev/null ${PKG_SYSCONFDIR}/xcdroast.conf

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

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/pcre/buildlink2.mk"
.include "../../devel/pkg-config/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
