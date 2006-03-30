# $NetBSD: Makefile,v 1.18 2006/03/30 03:44:42 jlam Exp $
#

DISTNAME=		diffutils-2.8.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=diffutils/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/diffutils/diffutils.html
COMMENT=		GNU diff utilities - find the differences between files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
INFO_FILES=		# PLIST

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX:Q}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.include "../../mk/bsd.pkg.mk"
