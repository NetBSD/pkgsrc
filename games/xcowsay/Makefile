# $NetBSD: Makefile,v 1.26 2020/03/10 22:10:00 wiz Exp $

DISTNAME=	xcowsay-1.4
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	https://www.nickg.me.uk/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.doof.me.uk/xcowsay/
COMMENT=	Display a cow and message on your desktop
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

.include "options.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
