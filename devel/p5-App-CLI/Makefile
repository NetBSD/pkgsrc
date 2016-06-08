# $NetBSD: Makefile,v 1.16 2016/06/08 19:22:33 wiz Exp $

DISTNAME=	App-CLI-0.313
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/App-CLI/
COMMENT=	Dispatcher module for command line interface programs
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/App/CLI/.packlist

#IC5.8.8DEPENDS+=       p5-Getopt-Long>=2.35:../../devel/p5-Getopt-Long
#DEPENDS+=	{perl>=5.10.0,p5-Locale-Maketext-Simple>=0.16}:../../misc/p5-Locale-Maketext-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
