# $NetBSD: Makefile,v 1.2 2005/01/23 14:40:12 peter Exp $
#

DISTNAME=		tls1.5.0-src
PKGNAME=		tcl-tls-1.5.0
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tls/}

MAINTAINER=		peter@pointless.nl
HOMEPAGE=		http://tls.sourceforge.net/
COMMENT=		TLS (aka SSL) Channel for the Tcl language

WRKSRC=			${WRKDIR}/tls1.5

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl-dir=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE:Q}

.include "../../lang/tcl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
