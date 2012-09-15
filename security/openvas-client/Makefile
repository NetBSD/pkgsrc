# $NetBSD: Makefile,v 1.15 2012/09/15 10:06:16 obache Exp $
#

DISTNAME=	openvas-client-2.0.1
PKGREVISION=	12
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/552/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openvas.org/
COMMENT=	Client for the Open Vulnerability Assessment System

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	YES
BUILD_DEFS+=	VARBASE
USE_X11=	YES

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-x11
CONFIGURE_ARGS+=	--with-ssl

.include "../../security/openvas-libraries/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
