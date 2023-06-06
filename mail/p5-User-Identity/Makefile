# $NetBSD: Makefile,v 1.34 2023/06/06 12:41:49 riastradh Exp $

DISTNAME=	User-Identity-1.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=User/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perl.overmeer.net/userid/
#HOMEPAGE=	http://search.cpan.org/dist/User-Identity/
COMMENT=	Helps maintaining user information from various sources
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Geography-Countries>=1.4:../../geography/p5-Geography-Countries
TOOL_DEPENDS+=	p5-Test-Pod>=1.0:../../devel/p5-Test-Pod

PERL5_PACKLIST=	auto/User/Identity/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
