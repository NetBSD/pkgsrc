# $NetBSD: Makefile,v 1.7 2003/10/19 01:41:59 heinz Exp $
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

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV=		PERL=${PERL5}
_STRIPFLAG_INSTALL=	# none

USE_MAKEINFO=		YES
INFO_FILES=		automake14.info

TEST_TARGET=		check

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
