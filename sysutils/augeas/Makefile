# $NetBSD: Makefile,v 1.20 2026/01/07 08:48:48 wiz Exp $

DISTNAME=	augeas-1.14.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=hercules-team/}
GITHUB_RELEASE=	release-${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://augeas.net/
COMMENT=	Tool for editing configuration programmatically
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	augeas.pc.in
TEST_TARGET=		check

# rl_char_is_quoted_p
.include "../../devel/readline/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
