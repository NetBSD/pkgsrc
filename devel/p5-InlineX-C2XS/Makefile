# $NetBSD: Makefile,v 1.23 2023/02/11 23:08:51 wen Exp $
#

DISTNAME=	InlineX-C2XS-0.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Inline/SISYPHUS/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://metacpan.org/release/InlineX-C2XS
COMMENT=	Convert from Inline C code to XS
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Inline>=0.47:../../devel/p5-Inline
DEPENDS+=	p5-Inline-C>=0.54:../../devel/p5-Inline-C

PERL5_PACKLIST=		auto/InlineX/C2XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
