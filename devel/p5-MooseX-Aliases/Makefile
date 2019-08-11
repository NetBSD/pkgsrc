# $NetBSD: Makefile,v 1.12 2019/08/11 13:19:55 wiz Exp $
#

DISTNAME=	MooseX-Aliases-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-Aliases
COMMENT=	Easy aliasing of methods and attributes in Moose
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=2.0000:../../devel/p5-Moose

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Aliases/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
