# $NetBSD: Makefile,v 1.10 2013/02/06 19:31:04 jperkin Exp $
#

DISTNAME=	openvas-libnasl-2.0.0
PKGREVISION=	6
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/549/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openvas.org/
COMMENT=	Libraries for the Open Vulnerability Assessment System

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
BUILD_DEFS+=	VARBASE
USE_TOOLS+=	bison pkg-config

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

.include "../../security/openvas-libraries/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
