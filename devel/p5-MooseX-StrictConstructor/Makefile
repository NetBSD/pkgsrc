# $NetBSD: Makefile,v 1.3 2009/09/12 20:48:20 sno Exp $
#

DISTNAME=	MooseX-StrictConstructor-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-StrictConstructor/
COMMENT=	Make your object constructors blow up on unknown attributes
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=0.74:../../devel/p5-Moose

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/StrictConstructor/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
