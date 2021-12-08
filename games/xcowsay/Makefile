# $NetBSD: Makefile,v 1.29 2021/12/08 16:04:43 adam Exp $

DISTNAME=	xcowsay-1.5.1
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://www.nickg.me.uk/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.doof.me.uk/xcowsay/
COMMENT=	Display a cow and message on your desktop
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

.include "options.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
