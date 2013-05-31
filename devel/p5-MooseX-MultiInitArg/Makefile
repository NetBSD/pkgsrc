# $NetBSD: Makefile,v 1.7 2013/05/31 12:40:33 wiz Exp $
#

DISTNAME=	MooseX-MultiInitArg-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-MultiInitArg/
COMMENT=	Attributes with aliases for constructor arguments
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/MultiInitArg/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
