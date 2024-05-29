# $NetBSD: Makefile,v 1.14 2024/05/29 16:34:21 adam Exp $

DISTNAME=	augeas-1.12.0
PKGREVISION=	9
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
