# $NetBSD: Makefile,v 1.24 2001/11/28 05:20:46 jlam Exp $
# FreeBSD Id: Makefile,v 1.5 1997/09/19 09:29:04 max Exp
#

DISTNAME=	automake-1.4-p5
PKGNAME=	${DISTNAME:C/-p/./}nb1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/}

MAINTAINER=	fujimoto@oscar.elec.waseda.ac.jp
HOMEPAGE=	http://www.gnu.org/software/automake/automake.html
COMMENT=	GNU Standards-compliant Makefile generator

DEPENDS=	autoconf>=2.13:../../devel/autoconf

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV=		PERL=${PERL5}
STRIPFLAG=		# none

INFO_FILES=	automake.info

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
