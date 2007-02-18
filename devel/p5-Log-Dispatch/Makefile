# $NetBSD: Makefile,v 1.20 2007/02/18 02:45:54 wiz Exp $

DISTNAME=	Log-Dispatch-2.16
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ldi
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Log-Dispatch/
COMMENT=	Perl module for logging messages to multiple outputs

DEPENDS+=	p5-Params-Validate>=0.15:../../devel/p5-Params-Validate

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Log/Dispatch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
