# $NetBSD: Makefile,v 1.36 2012/10/31 11:18:27 asau Exp $

DISTNAME=	Log-Dispatch-2.32
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5ldi
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Log-Dispatch/
COMMENT=	Perl module for logging messages to multiple outputs
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Load-[0-9]*:../../devel/p5-Class-Load
DEPENDS+=	p5-Params-Validate>=0.15:../../devel/p5-Params-Validate

PERL5_PACKLIST=		auto/Log/Dispatch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
