# $NetBSD: Makefile,v 1.11 2004/12/20 11:31:01 grant Exp $

DISTNAME=	Log-Dispatch-2.08
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ldi
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for logging messages to multiple outputs

BUILD_DEPENDS+=	p5-Module-Build>=0.20:../../devel/p5-Module-Build

DEPENDS+=	p5-Params-Validate>=0.15:../../devel/p5-Params-Validate
DEPENDS+=	p5-Test-Simple>=0.17:../../devel/p5-Test-Simple

USE_BUILDLINK3=		YES

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
