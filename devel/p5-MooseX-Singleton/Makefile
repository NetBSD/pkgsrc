# $NetBSD: Makefile,v 1.1.1.1 2009/04/27 04:19:39 seb Exp $
#

DISTNAME=	MooseX-Singleton-0.17
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Singleton/
COMMENT=	Perl 5 module to turn Moose class into a singleton
#LICENSE=	artistic OR gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Singleton/.packlist

DEPENDS+=	p5-Moose>=0.74:../../devel/p5-Moose
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
