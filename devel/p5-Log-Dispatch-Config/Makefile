# $NetBSD: Makefile,v 1.7 2004/12/20 11:31:01 grant Exp $

DISTNAME=	Log-Dispatch-Config-0.12
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ldi
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Configure Log::Dispatch with a config file, a la Java's log4j

DEPENDS+=	p5-Test-Simple>=0.41:../../devel/p5-Test-Simple
DEPENDS+=	p5-IO-stringy>=2.108:../../devel/p5-IO-stringy
DEPENDS+=	p5-AppConfig>=1.52:../../devel/p5-AppConfig
DEPENDS+=	p5-Log-Dispatch>=1.79:../../devel/p5-Log-Dispatch

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Log/Dispatch/Config/.packlist

.include "../../devel/p5-Test-Harness/depends.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
