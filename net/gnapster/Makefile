# $NetBSD: Makefile,v 1.22 2003/03/27 15:59:05 wiz Exp $

DISTNAME=	gnapster-1.5.0
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnapster/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/gnapster/
COMMENT=	simple client for the online mp3 community

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
