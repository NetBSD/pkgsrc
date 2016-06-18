# $NetBSD: Makefile,v 1.21 2016/06/18 20:18:53 mef Exp $

DISTNAME=	Devel-PPPort-3.34
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-PPPort/
COMMENT=	Perl5 module to bring newer features to older perl
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Devel/PPPort/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
