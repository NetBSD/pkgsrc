# $NetBSD: Makefile,v 1.12 2005/02/21 12:17:08 wiz Exp $

DISTNAME=	Log-Dispatch-2.10
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ldi
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~drolsky/Log-Dispatch/
COMMENT=	Perl module for logging messages to multiple outputs

DEPENDS+=	p5-Params-Validate>=0.15:../../devel/p5-Params-Validate
DEPENDS+=	p5-Test-Simple>=0.17:../../devel/p5-Test-Simple

USE_BUILDLINK3=			YES
PERL5_USES_MODULE_BUILD=	YES

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
