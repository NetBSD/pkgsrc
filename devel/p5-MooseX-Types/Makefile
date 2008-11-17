# $NetBSD: Makefile,v 1.3 2008/11/17 04:03:23 he Exp $
#

DISTNAME=	MooseX-Types-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Types/
COMMENT=	Organise your Moose types in libraries

DEPENDS+=	p5-Moose>=0.24:../../devel/p5-Moose
DEPENDS+=	p5-Sub-Install>=0.922:../../devel/p5-Sub-Install
DEPENDS+=	p5-namespace-clean>=0.04:../../devel/p5-namespace-clean
DEPENDS+=	p5-Carp-Clan>=0:../../devel/p5-Carp-Clan
DEPENDS+=	p5-Class-MOP>=0:../../devel/p5-Class-MOP

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Types/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
