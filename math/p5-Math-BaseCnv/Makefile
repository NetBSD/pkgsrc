# $NetBSD: Makefile,v 1.14 2017/02/11 11:26:42 mef Exp $
#

DISTNAME=	Math-BaseCnv-1.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-BaseCnv/
COMMENT=	Fast functions to CoNVert between number Bases
LICENSE=	gnu-gpl-v3

# actually, TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage

PERL5_PACKLIST=		auto/Math/BaseCnv/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
