# $NetBSD: Makefile,v 1.13 2011/08/14 12:26:21 obache Exp $

DISTNAME=	MooseX-MethodAttributes-0.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-MethodAttributes/
COMMENT=	Perl5 module for code attribute introspection
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=0.98:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types>=0.21:../../devel/p5-MooseX-Types
DEPENDS+=	p5-namespace-clean>=0.10:../../devel/p5-namespace-clean

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/MooseX/MethodAttributes/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
