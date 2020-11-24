# $NetBSD: Makefile,v 1.11 2020/11/24 17:49:41 nia Exp $

DISTNAME=	qstat-2.14
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=multiplay/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/multiplay/qstat
COMMENT=	Program that gathers real-time statistics from game servers
LICENSE=	artistic-2.0

USE_TOOLS+=	autoconf automake autoreconf

GNU_CONFIGURE=	yes
CPPFLAGS+=	-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/qstat.cfg ${PKG_SYSCONFDIR}/qstat.cfg

INSTALLATION_DIRS=	bin

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../mk/bsd.pkg.mk"
