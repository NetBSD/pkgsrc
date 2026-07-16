# $NetBSD: Makefile,v 1.26 2026/07/16 19:01:52 wiz Exp $

DISTNAME=	AppConfig-Std-1.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AppConfig/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/AppConfig-Std
COMMENT=	AppConfig::Std Perl module
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/AppConfig/Std/.packlist

DEPENDS+=		p5-AppConfig>=1.52:../../devel/p5-AppConfig

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
