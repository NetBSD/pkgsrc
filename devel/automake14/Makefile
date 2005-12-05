# $NetBSD: Makefile,v 1.14 2005/12/05 20:50:02 rillig Exp $
#

DISTNAME=	automake-1.4-p6
PKGNAME=	automake14-1.4.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/automake/automake.html
COMMENT=	GNU Standards-compliant Makefile generator (old version)

DEPENDS+=	autoconf213>=2.13:../../devel/autoconf213

CONFLICTS=	automake<1.6

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
_STRIPFLAG_INSTALL=	# none

USE_TOOLS+=		perl:run
USE_MAKEINFO=		YES
INFO_FILES=		automake14.info

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
