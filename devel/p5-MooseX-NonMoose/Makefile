# $NetBSD: Makefile,v 1.7 2011/08/14 12:26:22 obache Exp $
#

DISTNAME=	MooseX-NonMoose-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-NonMoose/
COMMENT=	Perl 5 module to subclass non-Moose classes with Moose
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/NonMoose/.packlist

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Moose>=1.08:../../devel/p5-Moose

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
