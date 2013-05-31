# $NetBSD: Makefile,v 1.17 2013/05/31 12:41:20 wiz Exp $

DISTNAME=	User-Identity-0.93
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=User/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perl.overmeer.net/userid/
#HOMEPAGE=	http://search.cpan.org/dist/User-Identity/
COMMENT=	Helps maintaining user information from various sources
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Geography-Countries>=1.4:../../geography/p5-Geography-Countries
BUILD_DEPENDS+=	p5-Test-Pod>=1.0:../../devel/p5-Test-Pod

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/User/Identity/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
