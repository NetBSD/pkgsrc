# $NetBSD: Makefile,v 1.4 2005/04/11 21:47:20 tv Exp $
#

DISTNAME=		tls1.5.0-src
PKGNAME=		tcl-tls-1.5.0
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tls/}

MAINTAINER=		peter@pointless.nl
HOMEPAGE=		http://tls.sourceforge.net/
COMMENT=		TLS (aka SSL) Channel for the Tcl language

WRKSRC=			${WRKDIR}/tls1.5

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl-dir=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE:Q}
MAKE_ENV+=		TCLLIB="${BUILDLINK_PREFIX.tcl}/lib"

.include "../../lang/tcl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
