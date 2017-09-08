# $NetBSD: Makefile,v 1.27 2017/09/08 13:53:25 jperkin Exp $

DISTNAME=	tinc-1.0.32
CATEGORIES=	net
MASTER_SITES=	http://www.tinc-vpn.org/packages/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tinc-vpn.org/
COMMENT=	Virtual Private Network (VPN) daemon
LICENSE=	gnu-gpl-v2

INFO_FILES=		yes
USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		yes

SUBST_CLASSES+=		mdoc
SUBST_FILES.mdoc=	doc/tinc.conf.5.in
SUBST_SED.mdoc+=	-e '/^$$/d'
SUBST_STAGE.mdoc=	pre-patch

.include "../../archivers/lzo/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
