# $NetBSD: Makefile,v 1.17 2001/12/12 18:25:39 wiz Exp $

DISTNAME=	gnapster-1.5.0
CATEGORIES=	net
MASTER_SITES=	http://www.faradic.net/~jasta/files/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.faradic.net/~jasta/programs.html
COMMENT=	simple client for the online mp3 community

BUILD_USES_MSGFMT=	YES

USE_GMAKE=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_BUILDLINK_ONLY=	YES

GNU_CONFIGURE=	YES

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
