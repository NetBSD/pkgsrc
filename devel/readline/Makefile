# $NetBSD: Makefile,v 1.41 2006/11/05 17:49:34 joerg Exp $
#

DISTNAME=	readline-5.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=readline/}

#PATCH_SITES=	${MASTER_SITE_GNU:=readline/readline-5.1-patches/}
#PATCHFILES=	readline51-001

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cnswww.cns.cwru.edu/php/chet/readline/rltop.html
COMMENT=	GNU library that can recall and edit previous input

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		# PLIST

BUILD_TARGET=		all-libtool
INSTALL_TARGET=		install-libtool

.include "../../mk/bsd.pkg.mk"
