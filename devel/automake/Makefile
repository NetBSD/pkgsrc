# $NetBSD: Makefile,v 1.30 2002/09/25 19:22:30 wiz Exp $
#

DISTNAME=	automake-1.4-p6
PKGNAME=	${DISTNAME:C/-p/./}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/automake/automake.html
COMMENT=	GNU Standards-compliant Makefile generator

DEPENDS=	autoconf>=2.13:../../devel/autoconf

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV=		PERL=${PERL5}
_STRIPFLAG_INSTALL=	# none

INFO_FILES=		automake.info
TEXINFO_OVERRIDE=	YES

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
