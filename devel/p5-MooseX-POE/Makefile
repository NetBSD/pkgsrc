# $NetBSD: Makefile,v 1.8 2019/06/30 20:15:26 nia Exp $

DISTNAME=	MooseX-POE-0.215
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-POE
COMMENT=	Moose wrapper around a POE::Session
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/MooseX/POE/.packlist

BUILD_DEPENDS+=	p5-Test-Fatal>=0.003:../../devel/p5-Test-Fatal
DEPENDS+=	p5-POE>=1.310:../../devel/p5-POE
DEPENDS+=	p5-Moose>=2.0002:../../devel/p5-Moose

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
