# $NetBSD: Makefile,v 1.3 2009/08/09 07:54:42 wiz Exp $

DISTNAME=		libixp-0.5
CATEGORIES=		devel
MASTER_SITES=		http://code.suckless.org/dl/libs/

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://libs.suckless.org/libixp
COMMENT=		Stand-alone client/server 9P library
#LICENSE=		mit AND lpl (plan 9 license)

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}

USE_TOOLS+=		gmake

.include "../../mk/bsd.pkg.mk"
