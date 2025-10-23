# $NetBSD: Makefile,v 1.87 2025/10/23 20:38:44 wiz Exp $

DISTNAME=		gkrellmwireless-2.0.3
PKGNAME=		${DISTNAME:S/gkrellm/gkrellm-/}
PKGREVISION=		66
CATEGORIES=		net sysutils
MASTER_SITES=		${MASTER_SITE_GENTOO:=distfiles/e3/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Wavelan signal strength monitor for gkrellm
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/gkrellmwireless
USE_TOOLS+=		gmake pkg-config

INSTALLATION_DIRS=	lib/gkrellm2/plugins

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
