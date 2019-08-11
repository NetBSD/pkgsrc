# $NetBSD: Makefile,v 1.15 2019/08/11 13:18:52 wiz Exp $

DISTNAME=	B-Compiling-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=B/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/B-Compiling
COMMENT=	Expose PL_compiling to perl
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/B/Compiling/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
