# $NetBSD: Makefile,v 1.2.2.2 2002/06/23 18:45:31 jlam Exp $
#

DISTNAME=	generator-0.34
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.squish.net/generator/files/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.sqish.net/generator/
COMMENT=	Sega Mega drive genesis emulator

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-gtk --with-raze

.include "../../devel/SDL/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
