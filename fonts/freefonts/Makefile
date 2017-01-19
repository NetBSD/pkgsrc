# $NetBSD: Makefile,v 1.16 2017/01/19 18:52:09 agc Exp $

DISTNAME=	freefonts-0.10
PKGREVISION=	3
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SUNSITE:=X11/fonts/}
MASTER_SITES+=	http://download.gimp.org/pub/gimp/fonts/

MAINTAINER=	reed@reedmedia.net
COMMENT=	Collection of 79 freely available fonts

PKG_DESTDIR_SUPPORT=	destdir

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=	gzcat tar
FONTS_DIRS.x11=	${PREFIX}/share/fonts/X11/freefont
REQD_DIRS=	${PREFIX}/share/fonts/X11/freefont

INSTALLATION_DIRS=	share/fonts/X11

do-install:
	${GZCAT} ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
	    ${TAR} -xf - -C ${DESTDIR}${PREFIX}/share/fonts/X11
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/share/fonts/X11/freefont/*
	${CHOWN} ${SHAREOWN}:${SHAREGRP} \
		${DESTDIR}${PREFIX}/share/fonts/X11/freefont/*

.include "../../mk/bsd.pkg.mk"
