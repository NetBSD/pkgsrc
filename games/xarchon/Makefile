# $NetBSD: Makefile,v 1.15 2000/08/23 23:14:26 tron Exp $
#

DISTNAME=	xarchon-0.50
CATEGORIES=	games x11
MASTER_SITES=	http://xarchon.seul.org/ \
		ftp://xarchon.seul.org/pub/xarchon/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://xarchon.seul.org/

DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	esound-*:../../audio/esound

USE_XPM=	YES
GNU_CONFIGURE=	YES
EVAL_PREFIX+=	GTKDIR=gtk+ XPMDIR=xpm
CONFIGURE_ARGS+=--with-xpm-prefix=${XPMDIR} \
		--with-gtk-prefix=${GTKDIR} \
		--with-esd-prefix=${LOCALBASE}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	CC="${CC}"
.endif

.include "../../mk/bsd.pkg.mk"
