# $NetBSD: Makefile,v 1.1.1.1 2011/08/23 08:50:14 abs Exp $

DISTNAME=	Eval-Closure-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DO/DOY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~doy/Eval-Closure/
COMMENT=	Safely and cleanly create closures via string eval
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter>=0.980:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Try-Tiny>=0.02:../../devel/p5-Try-Tiny

BUILD_DEPENDS+=	p5-Test-Fatal>=0.05:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Requires>=0.05:../../devel/p5-Test-Requires

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Eval/Closure/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
