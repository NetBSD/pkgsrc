# $NetBSD: Makefile,v 1.6 2011/08/14 12:26:21 obache Exp $
#

DISTNAME=	MooseX-LazyRequire-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-LazyRequire/
COMMENT=	Required attributes which fail only when trying to use them
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=0.94:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types-[0-9]*:../../devel/p5-MooseX-Types
DEPENDS+=	p5-aliased>=0.30:../../devel/p5-aliased
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/LazyRequire/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
