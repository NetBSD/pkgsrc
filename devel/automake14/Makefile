# $NetBSD: Makefile,v 1.18 2007/09/20 22:12:08 wiz Exp $
#

DISTNAME=	automake-1.4-p6
PKGNAME=	automake14-1.4.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/automake/automake.html
COMMENT=	GNU Standards-compliant Makefile generator (old version)

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	autoconf213>=2.13:../../devel/autoconf213

CONFLICTS=	automake<1.6

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
_STRIPFLAG_INSTALL=	# none

USE_TOOLS+=		makeinfo perl:run
INFO_FILES=		# PLIST

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
