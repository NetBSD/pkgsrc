# $NetBSD: Makefile,v 1.13 2007/02/27 09:14:24 wiz Exp $
#

DISTNAME=	ExtUtils-PkgConfig-1.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Simplistic perl interface to pkg-config

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/ExtUtils/PkgConfig/.packlist
USE_TOOLS=	pkg-config

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
