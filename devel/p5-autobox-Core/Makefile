# $NetBSD: Makefile,v 1.2 2010/03/10 15:59:30 sno Exp $
#

DISTNAME=	autobox-Core-1.0
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SW/SWALTERS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/autobox-Core/
COMMENT=	Perl 5 module adding core built-in functions in primitive types
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/autobox/Core/.packlist

DEPENDS+=	p5-autobox>=0.11:../../devel/p5-autobox

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
