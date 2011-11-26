# $NetBSD: Makefile,v 1.17 2011/11/26 04:39:35 sbd Exp $

DISTNAME=	ccache-3.1.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://samba.org/ftp/ccache/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ccache.samba.org/
COMMENT=	Cache for C/C++ compilers
#LICENSE=	gnu-gpl-v3 AND modified-bsd AND public-domain # AND zlib-license

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

CCACHE_DEFAULT_MAXSIZE?=	1048576
BUILD_DEFS+=			CCACHE_DEFAULT_MAXSIZE
CPPFLAGS+=			-DDEFAULT_MAXSIZE=${CCACHE_DEFAULT_MAXSIZE}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
