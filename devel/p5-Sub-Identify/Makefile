# $NetBSD: Makefile,v 1.14 2016/01/07 11:30:15 wiz Exp $

DISTNAME=	Sub-Identify-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sub-Identify/
COMMENT=	Perl 5 module to retrieve names of code references
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Sub/Identify/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
