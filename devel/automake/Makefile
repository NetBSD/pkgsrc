# $NetBSD: Makefile,v 1.27.2.2 2002/06/21 23:05:05 jlam Exp $
# FreeBSD Id: Makefile,v 1.5 1997/09/19 09:29:04 max Exp
#

DISTNAME=	automake-1.4-p5
PKGNAME=	${DISTNAME:C/-p/./}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/automake/automake.html
COMMENT=	GNU Standards-compliant Makefile generator

DEPENDS=	autoconf>=2.13:../../devel/autoconf

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV=		PERL=${PERL5}
STRIPFLAG=		# none

INFO_FILES=		automake.info
TEXINFO_OVERRIDE=	YES

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
