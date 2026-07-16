# $NetBSD: Makefile,v 1.11 2026/07/16 19:03:44 wiz Exp $

DISTNAME=	XString-0.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AT/ATOOMIC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/XString
COMMENT=	Isolated String helpers from B
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test2-Plugin-NoWarnings-[0-9]*:../../devel/p5-Test2-Plugin-NoWarnings
TEST_DEPENDS+=	p5-Test2-Tools-Explain-[0-9]*:../../devel/p5-Test2-Tools-Explain

PERL5_PACKLIST=	auto/XString/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
