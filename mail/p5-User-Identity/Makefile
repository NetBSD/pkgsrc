# $NetBSD: Makefile,v 1.23 2017/06/05 14:24:08 ryoon Exp $

DISTNAME=	User-Identity-0.94
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=User/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perl.overmeer.net/userid/
#HOMEPAGE=	http://search.cpan.org/dist/User-Identity/
COMMENT=	Helps maintaining user information from various sources
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Geography-Countries>=1.4:../../geography/p5-Geography-Countries
BUILD_DEPENDS+=	p5-Test-Pod>=1.0:../../devel/p5-Test-Pod

PERL5_PACKLIST=	auto/User/Identity/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
