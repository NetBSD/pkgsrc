# $NetBSD: Makefile,v 1.1 2013/10/11 11:06:49 wiz Exp $

DISTNAME=	MooX-Cmd-0.003
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/G/GE/GETTY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~getty/MooX-Cmd/
COMMENT=	Easy Moo style way to make command organized CLI apps
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-Record>=0.02:../../devel/p5-Data-Record
DEPENDS+=	p5-Moo>=0.090013:../../devel/p5-Moo
DEPENDS+=	p5-Package-Stash>=0.33:../../devel/p5-Package-Stash
DEPENDS+=	p5-Regexp-Common>=2011121001:../../textproc/p5-Regexp-Common

PERL5_PACKLIST=	auto/MooX/Cmd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
