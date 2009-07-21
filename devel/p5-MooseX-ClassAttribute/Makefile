# $NetBSD: Makefile,v 1.5 2009/07/21 06:16:24 sno Exp $
#

DISTNAME=	MooseX-ClassAttribute-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-ClassAttribute/
COMMENT=	Perl 5 module to declare class attributes Moose-style
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/ClassAttribute/.packlist
PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=	p5-Moose>=0.74:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-AttributeHelpers>=0.13:../../devel/p5-MooseX-AttributeHelpers

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
