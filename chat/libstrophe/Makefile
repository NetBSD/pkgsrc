# $NetBSD: Makefile,v 1.3 2023/11/02 13:30:46 nros Exp $

DISTNAME=	libstrophe-0.12.3
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=strophe/}
GITHUB_PROJECT=	libstrophe
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://strophe.im/libstrophe/
COMMENT=	XMPP library for C
LICENSE=	mit OR gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	libstrophe.pc.in

.include "../../textproc/expat/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
