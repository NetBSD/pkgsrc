# $NetBSD: Makefile,v 1.43 2008/02/27 18:16:37 jlam Exp $
#

DISTNAME=	readline-5.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=readline/}

#PATCH_SITES=	${MASTER_SITE_GNU:=readline/readline-5.1-patches/}
#PATCHFILES=	readline51-001

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cnswww.cns.cwru.edu/php/chet/readline/rltop.html
COMMENT=	GNU library that can recall and edit previous input
#LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		# PLIST

BUILD_TARGET=		all-libtool
INSTALL_TARGET=		install-libtool

.include "../../mk/termlib.buildlink3.mk"

.if ${TERMLIB_TYPE} == "curses"
CONFIGURE_ARGS+=	--with-curses
.endif

.include "../../mk/bsd.pkg.mk"
