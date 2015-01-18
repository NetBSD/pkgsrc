# $NetBSD: Makefile,v 1.10 2015/01/18 10:09:20 wen Exp $
#

DISTNAME=	Log-Any-Adapter-Dispatch-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Log-Any-Adapter/
COMMENT=	Log::Any adapter uses Log::Dispatch for logging
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Log-Any-[0-9]*:../../devel/p5-Log-Any
DEPENDS+=	p5-Log-Dispatch>=2.26:../../devel/p5-Log-Dispatch

PERL5_PACKLIST=		auto/Log/Any/Adapter/Dispatch/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
