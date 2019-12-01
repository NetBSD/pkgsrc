# $NetBSD: Makefile,v 1.17 2019/12/01 05:18:56 kim Exp $
#

DISTNAME=		ywho-1.3
CATEGORIES=		net
MASTER_SITES=		http://software.kimmo.suominen.com/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Who, users, uptime on clients in a sun-RPC network

NO_CONFIGURE=		yes
MAKE_FLAGS+=		DEST=${DESTDIR}${PREFIX} PKGMANDIR=${PKGMANDIR}
MAKE_FLAGS+=		EXTRA_LIBS=${LIBS:Q}
BUILD_TARGET=		all

LIBS.SunOS+=		-lnsl

INSTALL_TARGET=		install install.man
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
