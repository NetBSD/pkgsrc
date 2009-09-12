# $NetBSD: Makefile,v 1.4 2009/09/12 20:49:51 sno Exp $
#

DISTNAME=	MooseX-Singleton-0.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Singleton/
COMMENT=	Perl 5 module to turn Moose class into a singleton
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Singleton/.packlist
PERL5_MODULE_TYPE=	Module::Install

DEPENDS+=	p5-Moose>=0.82:../../devel/p5-Moose
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
