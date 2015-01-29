# $NetBSD: Makefile,v 1.10 2015/01/29 08:49:35 mef Exp $

DISTNAME=	Eval-Closure-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DO/DOY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~doy/Eval-Closure/
COMMENT=	Safely and cleanly create closures via string eval
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny

BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

PERL5_PACKLIST=		auto/Eval/Closure/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
