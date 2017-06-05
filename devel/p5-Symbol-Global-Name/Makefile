# $NetBSD: Makefile,v 1.8 2017/06/05 14:23:37 ryoon Exp $

DISTNAME=	Symbol-Global-Name-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Symbol/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Symbol-Global-Name/
COMMENT=	Finds name and type of a global variable
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.15.1,p5-ExtUtils-MakeMaker>=6.59}:../../devel/p5-ExtUtils-MakeMaker

PERL5_PACKLIST=	auto/Symbol/Global/Name/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
