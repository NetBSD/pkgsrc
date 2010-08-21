# $NetBSD: Makefile,v 1.2 2010/08/21 16:34:09 seb Exp $
#

DISTNAME=	MooseX-Types-JSON-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Types-JSON/
COMMENT=	Perl 5 module providing JSON datatype for Moose
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/MooseX/Types/JSON/.packlist

DEPENDS+=	p5-JSON-XS>=2.00:../../converters/p5-JSON-XS
DEPENDS+=	p5-Moose>=0.82:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types>=0.15:../../devel/p5-MooseX-Types

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
