# $NetBSD: Makefile,v 1.19 2017/03/31 10:32:20 wiz Exp $

DISTNAME=	openvas-libraries-2.0.0
PKGREVISION=	11
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/548/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openvas.org/
COMMENT=	Libraries for the Open Vulnerability Assessment System

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
MAKE_JOBS_SAFE=	NO
BUILD_DEFS+=	VARBASE
USE_LANGUAGES=	c++ c
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

# DragonFly-2.8.2 has dn_expand(3) in libc, and not have libresolv.
BUILDLINK_TRANSFORM.DragonFly+=	rm:-lresolv

BROKEN=		Does not build with gnutls-3.5 -- newer versions available.

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
