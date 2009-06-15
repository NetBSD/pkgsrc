# $NetBSD: Makefile,v 1.5 2009/06/15 21:25:57 sno Exp $
#

DISTNAME=	MooseX-AttributeHelpers-0.19
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-AttributeHelpers/
COMMENT=	Perl 5 module providing extensions to Moose attributes interface
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty

BUILD_DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception
DEPENDS+=	p5-Moose>=0.56:../../devel/p5-Moose

PERL5_PACKLIST=	auto/MooseX/AttributeHelpers/.packlist
PERL5_MODULE_TYPE=	Module::Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
