# $NetBSD: Makefile,v 1.23 2014/10/19 20:25:39 adam Exp $

DISTNAME=	ccache-3.1.10
CATEGORIES=	devel
MASTER_SITES=	http://samba.org/ftp/ccache/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ccache.samba.org/
COMMENT=	Cache for C/C++ compilers
LICENSE=	gnu-gpl-v3 AND modified-bsd AND public-domain AND zlib

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

CCACHE_DEFAULT_MAXSIZE?=	1048576
BUILD_DEFS+=			CCACHE_DEFAULT_MAXSIZE
CPPFLAGS+=			-DDEFAULT_MAXSIZE=${CCACHE_DEFAULT_MAXSIZE}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
