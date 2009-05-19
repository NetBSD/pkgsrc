# $NetBSD: Makefile,v 1.1.1.1 2009/05/19 22:12:19 sno Exp $
#

DISTNAME=	MooseX-SemiAffordanceAccessor-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-SemiAffordanceAccessor/
COMMENT=	Perl 5 module to name your accessors foo() and set_foo()
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/MooseX/SemiAffordanceAccessor/.packlist

DEPENDS+=	p5-Moose>=0.56:../../devel/p5-Moose

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
