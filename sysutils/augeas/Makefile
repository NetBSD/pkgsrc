# $NetBSD: Makefile,v 1.2 2015/01/06 22:59:07 joerg Exp $

DISTNAME=	augeas-1.3.0
CATEGORIES=	sysutils
MASTER_SITES=	http://download.augeas.net/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	http://augeas.net/
COMMENT=	Tool for editing configuration programmatically
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	augeas.pc.in

.include "../../mk/readline.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
