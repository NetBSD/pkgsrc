# $NetBSD: Makefile,v 1.23 2023/07/06 09:40:52 wiz Exp $
#

DISTNAME=	Math-BaseCnv-1.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Math-BaseCnv
COMMENT=	Fast functions to CoNVert between number Bases
LICENSE=	gnu-gpl-v3

# actually, TEST_DEPENDS
TOOL_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
TOOL_DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage

PERL5_PACKLIST=		auto/Math/BaseCnv/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
