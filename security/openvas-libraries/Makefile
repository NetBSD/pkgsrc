# $NetBSD: Makefile,v 1.14 2014/01/01 11:52:33 wiz Exp $
#

DISTNAME=	openvas-libraries-2.0.0
PKGREVISION=	8
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

.include "../../mk/bsd.prefs.mk"

# DragonFly-2.8.2 has dn_expand(3) in libc, and not have libresolv.
.if ${OPSYS} == "DragonFly"
BUILDLINK_TRANSFORM+=	rm:-lresolv
.endif

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
