# $NetBSD: Makefile,v 1.11 2014/01/01 11:52:33 wiz Exp $
#

DISTNAME=	openvas-server-2.0.0
PKGREVISION=	8
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/550/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openvas.org/
COMMENT=	Server for the Open Vulnerability Assessment System

.include "options.mk"

GNU_CONFIGURE=	YES
BUILD_DEFS+=	VARBASE
USE_TOOLS+=	pkg-config gettext:run
RCD_SCRIPTS=	openvasd

SUBST_CLASSES+=		user
SUBST_STAGE.user=	post-patch
SUBST_FILES.user=	openvas-adduser.in openvas-mkcert-client.in
SUBST_FILES.user+=	openvas-mkcert.in openvas-rmuser.in
SUBST_SED.user=		-e "s|/usr/bin/gettext|${BUILDLINK_PREFIX.gettext}/bin/gettext|g"
SUBST_MESSAGE.user=	Fixing administrative scripts.

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

.include "../../security/openvas-libraries/buildlink3.mk"
.include "../../security/openvas-libnasl/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
