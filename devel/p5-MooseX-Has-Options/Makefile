# $NetBSD: Makefile,v 1.11 2019/06/30 20:15:24 nia Exp $
#

DISTNAME=	MooseX-Has-Options-0.003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-Has-Options
COMMENT=	Succinct options for Moose
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Has/Options/.packlist

DEPENDS+=	p5-Package-Stash>=0.18:../../devel/p5-Package-Stash

BUILD_DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
BUILD_DEPENDS+=	p5-Test-Most-[0-9]*:../../devel/p5-Test-Most
BUILD_DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
BUILD_DEPENDS+=	p5-String-RewritePrefix-[0-9]*:../../textproc/p5-String-RewritePrefix

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
