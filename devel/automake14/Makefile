# $NetBSD: Makefile,v 1.9 2004/05/29 23:45:13 recht Exp $
#

DISTNAME=	automake-1.4-p6
PKGNAME=	automake14-1.4.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/automake/automake.html
COMMENT=	GNU Standards-compliant Makefile generator (old version)

DEPENDS=	autoconf213>=2.13:../../devel/autoconf213

CONFLICTS=	automake<1.6

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV=		PERL=${PERL5}
_STRIPFLAG_INSTALL=	# none

USE_MAKEINFO=		YES
INFO_FILES=		automake14.info

TEST_TARGET=		check

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
