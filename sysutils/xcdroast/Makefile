# $NetBSD: Makefile,v 1.9 2002/12/02 20:29:48 drochner Exp $

DISTNAME=	xcdroast-0.98alpha11
PKGNAME=	xcdroast-0.98a11
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xcdroast/}

MAINTAINER=	frueauf@netbsd.org
HOMEPAGE=	http://www.xcdroast.org/
COMMENT=	graphical user interface for the command-line cdrecord-tools

DEPENDS+=	cdrecord-xcdroast098a11-[0-9]*:../../sysutils/cdrecord-xcdroast

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --sysconfdir=${PKG_SYSCONFDIR}

#.if ${_OPSYS_HAS_OSSAUDIO} == "yes"
CFLAGS+=	-DHAVE_OSS
#.endif

DOCDIR=		${PREFIX}/share/doc/xcdroast
SUPPORT_FILES=	/dev/null ${PKG_SYSCONFDIR}/xcdroast.conf

#pre-build:
#	cd ${WRKSRC}; for file in io.c wavplay.c xcdroast.h; do		\
#		${SED}	-e "s|@PREFIX@|${PREFIX}|g"			\
#			-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"	\
#			-e "s|@DEVOSSAUDIO@|${DEVOSSAUDIO}|g"		\
#			$${file} > $${file}.fixed;			\
#		${MV} -f $${file}.fixed $${file};			\
#	done

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC};							\
	for file in ${WRKSRC}/doc/*; do	\
		${INSTALL_DATA} $${file} ${DOCDIR};			\
	done

# gdk-pixbuf implies gtk, glib, gettext-lib
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
