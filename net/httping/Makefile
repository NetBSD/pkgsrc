# $NetBSD: Makefile,v 1.21 2015/01/29 02:27:39 mef Exp $

DISTNAME=	httping-2.3.4
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
