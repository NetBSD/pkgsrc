# $NetBSD: Makefile,v 1.17 2016/06/08 19:22:34 wiz Exp $

DISTNAME=	Async-Interrupt-1.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
