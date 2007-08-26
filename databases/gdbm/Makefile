# $NetBSD: Makefile,v 1.40 2007/08/26 15:59:24 heinz Exp $
#

DISTNAME=	gdbm-1.8.3
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNU:=gdbm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gdbm/gdbm.html
COMMENT=	The GNU database manager

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		# PLIST
MAKE_FLAGS+=		INSTALL_ROOT=${DESTDIR:Q}

.include "../../mk/bsd.pkg.mk"
