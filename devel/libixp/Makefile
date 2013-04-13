# $NetBSD: Makefile,v 1.8 2013/04/13 07:55:02 ghen Exp $

DISTNAME=		libixp-0.4
CATEGORIES=		devel
MASTER_SITES=		http://dl.suckless.org/libs/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://libs.suckless.org/libixp
COMMENT=		Stand-alone client/server 9P library
#LICENSE=		mit AND lpl (plan 9 license)

INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}

USE_TOOLS+=		gmake

REPLACE_SH+=		util/compile

.include "../../mk/bsd.pkg.mk"
