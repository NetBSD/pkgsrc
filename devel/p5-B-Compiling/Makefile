# $NetBSD: Makefile,v 1.5 2012/10/31 11:17:40 asau Exp $

DISTNAME=	B-Compiling-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=B/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/B-Compiling/
COMMENT=	Expose PL_compiling to perl
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/B/Compiling/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
