# $NetBSD: Makefile,v 1.5 2010/02/15 15:21:45 sno Exp $
#

DISTNAME=	Devel-PartialDump-0.13
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-PartialDump/
COMMENT=	Perl 5 module to make partial dumps of data structures
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-namespace-clean>=0.08:../../devel/p5-namespace-clean

# For test target
BUILD_DEPENDS+=	p5-Test-Warn>=0.21:../../devel/p5-Test-Warn
BUILD_DEPENDS+=	p5-Test-use-ok-[0-9]*:../../devel/p5-Test-use-ok

REPLACE_PERL+=	lib/Devel/PartialDump.pm

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Devel/PartialDump/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
