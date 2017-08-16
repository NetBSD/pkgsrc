# $NetBSD: Makefile,v 1.11 2017/08/16 20:45:35 wiz Exp $

DISTNAME=		libixp-0.4
CATEGORIES=		devel
MASTER_SITES=		http://dl.suckless.org/libs/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://libs.suckless.org/libixp
COMMENT=		Stand-alone client/server 9P library
#LICENSE=		mit AND lpl (plan 9 license)

INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}

USE_TOOLS+=		gmake

REPLACE_SH+=		util/compile

CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS
LDFLAGS.SunOS+=		-lsocket

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
