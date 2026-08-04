# $NetBSD: Makefile,v 1.2 2026/08/04 20:29:11 wiz Exp $

DISTNAME=	openrrcp-0.2.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openrrcp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	RealTek	Remote Control Protocol tools
LICENSE=	gnu-gpl-v2

INSTALL_DIRS=	src

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

	
.include "../../net/libdnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
