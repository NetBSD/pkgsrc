# $NetBSD: Makefile,v 1.1.1.1 2002/10/03 19:26:12 wiz Exp $
#

DISTNAME=	automake-1.4-p6
PKGNAME=	automake14-1.4.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/automake/automake.html
COMMENT=	GNU Standards-compliant Makefile generator

DEPENDS=	autoconf213>=2.13:../../devel/autoconf213
#DEPENDS=	autoconf>=2.13:../../devel/autoconf

CONFLICTS=	automake<1.6

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV=		PERL=${PERL5}
_STRIPFLAG_INSTALL=	# none

INFO_FILES=		automake14.info
TEXINFO_OVERRIDE=	YES

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
