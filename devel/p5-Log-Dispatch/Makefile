# $NetBSD: Makefile,v 1.18 2006/03/04 21:29:22 jlam Exp $

DISTNAME=	Log-Dispatch-2.11
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ldi
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~drolsky/Log-Dispatch/
COMMENT=	Perl module for logging messages to multiple outputs

DEPENDS+=	p5-Params-Validate>=0.15:../../devel/p5-Params-Validate
DEPENDS+=	p5-Test-Simple>=0.17:../../devel/p5-Test-Simple

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Log/Dispatch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
