# $NetBSD: Makefile,v 1.12 2000/07/11 14:53:41 agc Exp $
#

DISTNAME=	xarchon-0.50
CATEGORIES=	games x11
MASTER_SITES=	http://xarchon.seul.org/ \
		ftp://xarchon.seul.org/pub/xarchon/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://xarchon.seul.org/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	esound-*:../../audio/esound

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-xpm-prefix=`${MAKE} show-xpm-prefix` \
		--with-gtk-prefix=`${MAKE} show-gtk+-prefix` \
		--with-esd-prefix=${LOCALBASE}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	CC="${CC}"
.endif

.include "../../mk/bsd.pkg.mk"
