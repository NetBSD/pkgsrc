# $NetBSD: Makefile,v 1.5 2003/09/21 21:33:09 kim Exp $
#

DISTNAME=	mpdist-3.7.1
PKGNAME=	mp-3.7.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpdist/}

MAINTAINER=     kim@tac.nyc.ny.us
HOMEPAGE=	http://mpdist.sourceforge.net/
COMMENT=	PostScript pretty printer

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_X11=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
.else
CONFIGURE_ARGS+=--enable-bsd-print
.endif

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
