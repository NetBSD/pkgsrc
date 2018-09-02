# $NetBSD: Makefile,v 1.16 2018/09/02 18:37:26 bsiegert Exp $
#

DISTNAME=		tcltls-1.7.16
PKGNAME=		tcl-tls-1.7.16
CATEGORIES=		security
MASTER_SITES=		http://core.tcl.tk/tcltls/uv/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://core.tcl.tk/tcltls/home
COMMENT=		TLS (aka SSL) Channel for the Tcl language
LICENSE=		2-clause-bsd

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-openssl-dir=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-tcl="${BUILDLINK_PREFIX.tcl}/lib"

TEST_TARGET=		test

.include "../../lang/tcl/Makefile.version"

.include "../../lang/tcl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
