# $NetBSD: Makefile,v 1.25 2017/08/14 20:38:02 wiz Exp $

DISTNAME=	httping-2.5
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

LDFLAGS.Darwin=		-lintl
LDFLAGS.NetBSD=		-lintl
LDFLAGS.SunOS=		-lnsl -lsocket -lresolv -lintl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
