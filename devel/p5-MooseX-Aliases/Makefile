# $NetBSD: Makefile,v 1.14 2021/05/24 19:51:09 wiz Exp $
#

DISTNAME=	MooseX-Aliases-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
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
