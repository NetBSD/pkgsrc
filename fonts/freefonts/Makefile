# $NetBSD: Makefile,v 1.3 2005/05/16 01:15:31 jlam Exp $
#

DISTNAME=	freefonts-0.10
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SUNSITE:=X11/fonts/} \
		ftp://ftp.gimp.org/pub/gimp/fonts/

MAINTAINER=	reed@reedmedia.net
COMMENT=	Collection of 79 freely available fonts

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_X11BASE=	yes
PKGSRC_USE_TOOLS+=	gtar

do-install:
	${GTAR} Cxzf ${PREFIX}/lib/X11/fonts \
		${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	${CHMOD} ${SHAREMODE} ${PREFIX}/lib/X11/fonts/freefont/*
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/X11/fonts/freefont/*

.include "../../mk/bsd.pkg.mk"
