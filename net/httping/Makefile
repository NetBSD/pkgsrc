# $NetBSD: Makefile,v 1.20 2014/02/18 12:13:01 jperkin Exp $

DISTNAME=	httping-2.3.3
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.vanheusden.com/httping/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vanheusden.com/httping/
COMMENT=	Like 'ping' but for http-requests
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt

CONFIGURE_ARGS+=	--with-openssl

.include "../../mk/bsd.prefs.mk"

LDFLAGS.NetBSD=		-lintl
LDFLAGS.SunOS=		-lnsl -lsocket -lresolv -lintl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
