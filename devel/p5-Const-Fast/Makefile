# $NetBSD: Makefile,v 1.7 2013/05/31 12:40:11 wiz Exp $

DISTNAME=	Const-Fast-0.013
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LE/LEONT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Const-Fast/
COMMENT=	Perl5 facility for creating read-only scalars, arrays, and hashes
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Sub-Exporter-Progressive-[0-9]*:../../devel/p5-Sub-Exporter-Progressive

PERL5_PACKLIST=		auto/Const/Fast/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
