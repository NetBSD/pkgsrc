# $NetBSD: Makefile,v 1.15 2019/08/11 13:19:46 wiz Exp $

DISTNAME=	Log-Report-Optional-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Log-Report-Optional
COMMENT=	Log::Report or ::Minimal
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-String-Print>=0.91:../../devel/p5-String-Print

PERL5_PACKLIST=		auto/Log/Report/Optional/.packlist
#PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
