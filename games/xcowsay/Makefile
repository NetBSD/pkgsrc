# $NetBSD: Makefile,v 1.17 2017/02/12 06:25:23 ryoon Exp $
#

DISTNAME=	xcowsay-1.3
PKGREVISION=	15
CATEGORIES=	misc
MASTER_SITES=	http://www.nickg.me.uk/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.doof.me.uk/xcowsay/
COMMENT=	Display a cow and message on your desktop
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=			pkg-config

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
