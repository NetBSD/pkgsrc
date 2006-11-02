# $NetBSD: Makefile,v 1.72 2006/11/02 18:17:22 joerg Exp $
#

DISTNAME=	automake-1.10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/} \
		ftp://sources.redhat.com/pub/automake/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/automake/automake.html
COMMENT=	GNU Standards-compliant Makefile generator

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	autoconf>=2.60:../../devel/autoconf

USE_TOOLS+=	gm4:run perl:run

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

PLIST_SUBST+=		PKG_DIR_VERSION=1.10
GNU_CONFIGURE=		YES
_STRIPFLAG_INSTALL=	# none
INFO_FILES=		# PLIST

# doesn't work because buildlink3 hides scripts
# from autoconf too well
#TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
