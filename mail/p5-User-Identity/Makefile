# $NetBSD: Makefile,v 1.39 2026/01/19 07:52:24 wiz Exp $

DISTNAME=	User-Identity-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=User/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://perl.overmeer.net/userid/
COMMENT=	Helps maintaining user information from various sources
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Geography-Countries>=1.4:../../geography/p5-Geography-Countries
DEPENDS+=	p5-Hash-Ordered>=0.014:../../devel/p5-Hash-Ordered

TOOL_DEPENDS+=	p5-Test-Pod>=1.0:../../devel/p5-Test-Pod

PERL5_PACKLIST=	auto/User/Identity/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
