# $NetBSD: Makefile,v 1.16 2001/02/16 15:10:59 wiz Exp $
#

DISTNAME=	xarchon-0.50
CATEGORIES=	games x11
MASTER_SITES=	http://xarchon.seul.org/ \
		ftp://xarchon.seul.org/pub/xarchon/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://xarchon.seul.org/
COMMENT=	Chess-like strategy game with battle options

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
