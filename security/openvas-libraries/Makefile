# $NetBSD: Makefile,v 1.4 2009/12/09 05:22:01 obache Exp $
#

DISTNAME=	openvas-libraries-2.0.0
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/548/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openvas.org/
COMMENT=	Libraries for the Open Vulnerability Assessment System

PKG_DESTDIR_SUPPORT=user-destdir

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
MAKE_JOBS_SAFE=	NO
BUILD_DEFS+=	VARBASE
USE_LANGUAGES=	c++ c
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
