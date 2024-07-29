# $NetBSD: Makefile,v 1.36 2024/07/29 04:46:47 wen Exp $

DISTNAME=	User-Identity-1.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=User/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perl.overmeer.net/userid/
#HOMEPAGE=	http://search.cpan.org/dist/User-Identity/
COMMENT=	Helps maintaining user information from various sources
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Geography-Countries>=1.4:../../geography/p5-Geography-Countries
DEPENDS+=	p5-Hash-Ordered>=0.014:../../devel/p5-Hash-Ordered

TOOL_DEPENDS+=	p5-Test-Pod>=1.0:../../devel/p5-Test-Pod

PERL5_PACKLIST=	auto/User/Identity/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
