# $NetBSD: Makefile,v 1.4 2008/02/05 23:47:18 heinz Exp $

DISTNAME=		hcidump-1.5.1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.geocities.com/m_evmenkin/

MAINTAINER=		plunky@rya-online.net
COMMENT=		Bluetooth traffic dumper, similar to tcpdump

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	NetBSD-[4-9].*-*	\
			NetBSD-3.99.[2-9][0-9]-*

WRKSRC=			${WRKDIR}/hcidump

INSTALL_MAKE_FLAGS+=	LIBOWN=${LIBOWN} LIBGRP=${LIBGRP} LIBMODE=${LIBMODE}
INSTALL_MAKE_FLAGS+=	BINOWN=${BINOWN} BINGRP=${BINGRP} BINMODE=${BINMODE}
INSTALL_MAKE_FLAGS+=	MANOWN=${MANOWN} MANGRP=${MANGRP} MANMODE=${MANMODE}

INSTALLATION_DIRS+=	${PKGMANDIR}/cat1
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	lib
INSTALLATION_DIRS+=	bin

.include "../../mk/bsd.pkg.mk"
