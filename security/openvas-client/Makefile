# $NetBSD: Makefile,v 1.43 2020/03/10 22:10:55 wiz Exp $
#

DISTNAME=	openvas-client-2.0.1
PKGREVISION=	37
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/552/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openvas.org/
COMMENT=	Client for the Open Vulnerability Assessment System

USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	YES
BUILD_DEFS+=	VARBASE
USE_X11=	YES

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-x11
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

.include "../../security/openvas-libraries/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
