# $NetBSD: Makefile,v 1.18 2021/07/05 07:46:19 wen Exp $

DISTNAME=	Log-Report-Optional-1.07
PKGNAME=	p5-${DISTNAME}
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
