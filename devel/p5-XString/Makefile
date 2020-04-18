# $NetBSD: Makefile,v 1.1 2020/04/18 01:12:03 mef Exp $

DISTNAME=	XString-0.002
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/A/AT/ATOOMIC/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/A/AT/ATOOMIC/
COMMENT=	Isolated String helpers from B
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test2-Plugin-NoWarnings-[0-9]*:../../devel/p5-Test2-Plugin-NoWarnings
TEST_DEPENDS+=	p5-Test2-Tools-Explain-[0-9]*:../../devel/p5-Test2-Tools-Explain

PERL5_PACKLIST=	auto/XString/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
