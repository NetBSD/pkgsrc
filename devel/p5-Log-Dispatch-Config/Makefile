# $NetBSD: Makefile,v 1.2 2002/10/20 23:35:09 seb Exp $

DISTNAME=	Log-Dispatch-Config-0.12
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ldi
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Configure Log::Dispatch with a config file, a la Java's log4j

DEPENDS+=	p5-Test-Harness>=2.01:../../devel/p5-Test-Harness
DEPENDS+=	p5-Test-Simple>=0.41:../../devel/p5-Test-Simple
DEPENDS+=	p5-IO-stringy>=2.108:../../devel/p5-IO-stringy
DEPENDS+=	p5-AppConfig>=1.52:../../devel/p5-AppConfig
DEPENDS+=	p5-Log-Dispatch>=1.79:../../devel/p5-Log-Dispatch

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Log/Dispatch/Config/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
