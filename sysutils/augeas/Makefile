# $NetBSD: Makefile,v 1.4 2019/02/12 12:21:00 adam Exp $

DISTNAME=	augeas-1.11.0
CATEGORIES=	sysutils
MASTER_SITES=	http://download.augeas.net/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	http://augeas.net/
COMMENT=	Tool for editing configuration programmatically
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	augeas.pc.in
TEST_TARGET=		check

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
