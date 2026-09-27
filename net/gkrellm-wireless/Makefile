# $NetBSD: Makefile,v 1.91 2026/09/27 11:38:00 tnn Exp $

DISTNAME=		gkrellmwireless-2.0.3
PKGNAME=		${DISTNAME:S/gkrellm/gkrellm-/}
PKGREVISION=		69
CATEGORIES=		net sysutils
MASTER_SITES=		${MASTER_SITE_GENTOO:=distfiles/e3/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Wavelan signal strength monitor for gkrellm
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/gkrellmwireless
USE_TOOLS+=		gmake pkg-config

INSTALLATION_DIRS=	lib/gkrellm2/plugins

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
