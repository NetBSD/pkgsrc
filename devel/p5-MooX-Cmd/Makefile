# $NetBSD: Makefile,v 1.19 2022/06/28 11:32:49 wiz Exp $

DISTNAME=	MooX-Cmd-0.017
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooX-Cmd
COMMENT=	Easy Moo style way to make command organized CLI apps
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moo>=0.090013:../../devel/p5-Moo
DEPENDS+=	p5-Package-Stash>=0.33:../../devel/p5-Package-Stash
DEPENDS+=	p5-Regexp-Common>=2011121001:../../textproc/p5-Regexp-Common
DEPENDS+=	p5-Module-Pluggable>=4.8:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-IO-TieCombine-[0-9]*:../../devel/p5-IO-TieCombine
DEPENDS+=	p5-MooX-Options>=4.002:../../devel/p5-MooX-Options

# for make test
BUILD_DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny

PERL5_PACKLIST=	auto/MooX/Cmd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
