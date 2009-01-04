# $NetBSD: Makefile,v 1.1.1.1 2009/01/04 01:08:52 adrianp Exp $
#

DISTNAME=	openvas-libraries-2.0.0
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/548/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.openvas.org/
COMMENT=	Libraries for the Open Vulnerability Assessment System

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
MAKE_JOBS_SAFE=	NO
BUILD_DEFS+=	VARBASE
USE_LANGUAGES+=	c++ c
USE_TOOLS=	pkg-config

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
