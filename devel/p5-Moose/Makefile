# $NetBSD: Makefile,v 1.3 2008/08/04 15:23:30 seb Exp $
#

DISTNAME=	Moose-0.55
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SA/SARTAK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://moose.perl.org/
COMMENT=	Postmodern object system for Perl 5

DEPENDS+=	p5-Class-MOP>=0.59:../../devel/p5-Class-MOP
DEPENDS+=	p5-Sub-Exporter>=0.972:../../devel/p5-Sub-Exporter

BUILD_DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-LongString-[0-9]*:../../devel/p5-Test-LongString

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Moose/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
