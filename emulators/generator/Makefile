# $NetBSD: Makefile,v 1.3 2002/08/27 18:32:13 jlam Exp $
#

DISTNAME=	generator-0.34
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.squish.net/generator/files/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.sqish.net/generator/
COMMENT=	Sega Mega drive genesis emulator

USE_BUILDLINK2=		# defined
USE_X11=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-gtk --with-raze

.include "../../devel/SDL/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
