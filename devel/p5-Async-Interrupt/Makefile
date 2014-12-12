# $NetBSD: Makefile,v 1.14 2014/12/12 11:13:21 mef Exp $

DISTNAME=	Async-Interrupt-1.2
PKGNAME=	p5-${DISTNAME}0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Async/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Async-Interrupt/
COMMENT=	Allow C/XS libraries to interrupt perl asynchronously
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Async/Interrupt/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
