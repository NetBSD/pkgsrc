# $NetBSD: Makefile,v 1.7 2004/04/25 02:44:36 snj Exp $
#

DISTNAME=	mpdist-3.7.1
PKGNAME=	mp-3.7.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpdist/}

MAINTAINER=     kim@tac.nyc.ny.us
HOMEPAGE=	http://mpdist.sourceforge.net/
COMMENT=	PostScript pretty printer

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_X11=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
.else
CONFIGURE_ARGS+=--enable-bsd-print
.endif

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
