# $NetBSD: Makefile,v 1.8 2002/09/26 12:29:55 jlam Exp $

DISTNAME=	xcdroast-0.98alpha9
PKGNAME=	xcdroast-0.98a9
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xcdroast/}

MAINTAINER=	frueauf@netbsd.org
HOMEPAGE=	http://www.xcdroast.org/
COMMENT=	graphical user interface for the command-line cdrecord-tools

DEPENDS+=	cdrecord-1.10:../../sysutils/cdrecord

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK2=	YES
USE_X11=	YES

BASE_VERS=	${PKGVERSION:C/a.*//}
PLIST_SUBST+=	BASE_VERS=${BASE_VERS}
MAKE_ENV+=	X_CFLAGS="${CFLAGS}"
MAKE_ENV+=	X_LDFLAGS="${LDFLAGS}"

#.if ${_OPSYS_HAS_OSSAUDIO} == "yes"
#CFLAGS+=	-DHAVE_OSS
#.endif

DOCDIR=		${PREFIX}/share/doc/xcdroast
SUPPORT_FILES=	/dev/null ${PKG_SYSCONFDIR}/xcdroast.conf

pre-build:
	cd ${WRKSRC}; for file in io.c wavplay.c xcdroast.h; do		\
		${SED}	-e "s|@PREFIX@|${PREFIX}|g"			\
			-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"	\
			-e "s|@DEVOSSAUDIO@|${DEVOSSAUDIO}|g"		\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC};							\
	for file in COPYING DOCUMENTATION FAQ README.nonroot; do	\
		${INSTALL_DATA} $${file} ${DOCDIR};			\
	done

.include "../../graphics/imlib/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
