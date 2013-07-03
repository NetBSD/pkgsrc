# $NetBSD: Makefile,v 1.1 2013/07/03 06:52:36 sno Exp $

DISTNAME=	Carp-Always-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Carp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Carp-Always/
COMMENT=	Perl5 module which warns and dies noisily with stack backtraces
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Base-[0-9]*:../../devel/p5-Test-Base

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Carp/Always/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
