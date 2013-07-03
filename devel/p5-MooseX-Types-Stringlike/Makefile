# $NetBSD: Makefile,v 1.1 2013/07/03 15:54:52 sno Exp $
#

DISTNAME=	MooseX-Types-Stringlike-0.001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Types-Stringlike/
COMMENT=	Commonly-used type constraints that do not ship with Moose by default
LICENSE=	apache-2.0

DEPENDS+=	p5-MooseX-Types-[0-9]*:../../devel/p5-MooseX-Types

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MooseX/Types/Stringlike/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
