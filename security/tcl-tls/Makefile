# $NetBSD: Makefile,v 1.9 2012/08/21 21:56:13 marino Exp $
#

DISTNAME=		tls1.5.0-src
PKGNAME=		tcl-tls-1.5.0
PKGREVISION=		3
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tls/}

PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tls.sourceforge.net/
COMMENT=		TLS (aka SSL) Channel for the Tcl language

WRKSRC=			${WRKDIR}/tls1.5

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl-dir=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE:Q}
MAKE_ENV+=		TCLLIB="${BUILDLINK_PREFIX.tcl}/lib"

TEST_TARGET=		test

.include "../../lang/tcl/Makefile.version"

PLIST_SUBST+=		TCL_SONUM=${TCL_SONUM}


.include "../../lang/tcl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
