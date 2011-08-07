# $NetBSD: Makefile,v 1.4 2011/08/07 12:57:24 adam Exp $

DISTNAME=	Sub-Override-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sub-Override/
COMMENT=	Perl 5 module for easily overriding subroutines
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Sub/Override/.packlist

BUILD_DEPENDS+=	p5-Sub-Uplevel-[0-9]*:../../devel/p5-Sub-Uplevel
BUILD_DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
