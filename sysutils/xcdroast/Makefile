# $NetBSD: Makefile,v 1.19 2003/08/30 22:51:38 jlam Exp $

DISTNAME=	xcdroast-0.98alpha14
PKGNAME=	xcdroast-0.98a14
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xcdroast/}

MAINTAINER=	frueauf@NetBSD.org
HOMEPAGE=	http://www.xcdroast.org/
COMMENT=	Graphical user interface for the command-line cdrecord-tools

DEPENDS+=	cdrecord-xcdroast-0.98a13.*:../cdrecord-xcdroast

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
USE_GMAKE=	yes

.if ${_OPSYS_HAS_OSSAUDIO} == "yes"
CFLAGS+=	-DHAVE_OSS
AUDIO_LIBS=	-lossaudio
CONFIGURE_ENV+=	AUDIO_LIBS=${AUDIO_LIBS}
.endif

DOCDIR=		${PREFIX}/share/doc/xcdroast
DOCFILES=	DOCUMENTATION FAQ README.nonroot
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
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${CP} -r ${WRKSRC}/doc/manual/* ${HTMLDIR}

# gdk-pixbuf implies gtk, glib, gettext-lib
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
