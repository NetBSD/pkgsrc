# $NetBSD: Makefile,v 1.13 2016/06/08 19:23:05 wiz Exp $
#

DISTNAME=	InlineX-C2XS-0.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Inline/SISYPHUS/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://search.cpan.org/dist/InlineX-C2XS/
COMMENT=	Convert from Inline C code to XS
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Inline>=0.47:../../devel/p5-Inline

PERL5_PACKLIST=		auto/InlineX/C2XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
