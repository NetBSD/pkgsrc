# $NetBSD: Makefile,v 1.20 2023/07/06 09:39:42 wiz Exp $
#

DISTNAME=	MooseX-Types-JSON-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-Types-JSON
COMMENT=	Perl 5 module providing JSON datatype for Moose
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/MooseX/Types/JSON/.packlist

DEPENDS+=	p5-JSON>=0:../../converters/p5-JSON
DEPENDS+=	p5-Moose>=0.82:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types>=0.15:../../devel/p5-MooseX-Types

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
