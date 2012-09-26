# $NetBSD: Makefile,v 1.6 2012/09/26 10:13:04 jperkin Exp $

DISTNAME=		libixp-0.4
CATEGORIES=		devel
MASTER_SITES=		http://dl.suckless.org/libs/

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://libs.suckless.org/libixp
COMMENT=		Stand-alone client/server 9P library
#LICENSE=		mit AND lpl (plan 9 license)

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}

USE_TOOLS+=		gmake

REPLACE_SH+=		util/compile

.include "../../mk/bsd.pkg.mk"
