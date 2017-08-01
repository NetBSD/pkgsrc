# $NetBSD: Makefile,v 1.3 2017/08/01 16:47:37 wiz Exp $
#

DISTNAME=	dotconf-1.3
CATEGORIES=	devel
MASTER_SITES=	http://files.opentts.org/dotconf/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.opentts.org/projects/dotconf
COMMENT=	Simple-to-use and powerful configuration-file parser library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	dotconf.pc.in

.include "../../mk/bsd.pkg.mk"
