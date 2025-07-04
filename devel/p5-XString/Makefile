# $NetBSD: Makefile,v 1.10 2025/07/04 08:47:01 wiz Exp $

DISTNAME=	XString-0.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
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
