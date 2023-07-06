# $NetBSD: Makefile,v 1.27 2023/07/06 09:40:57 wiz Exp $

DISTNAME=	Statistics-Descriptive-3.0800
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Statistics/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Statistics-Descriptive
COMMENT=	Perl module of basic descriptive statistical functions
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Statistics/Descriptive/.packlist
PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=	p5-List-MoreUtils>=0:../../devel/p5-List-MoreUtils

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
