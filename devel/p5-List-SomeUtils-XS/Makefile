# $NetBSD: Makefile,v 1.16 2023/07/06 09:39:25 wiz Exp $

DISTNAME=	List-SomeUtils-XS-0.58
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=List/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/List-SomeUtils-XS
COMMENT=	XS implementation for List::SomeUtils
LICENSE=	artistic-2.0

#DEPENDS+=	p5-List-MoreUtils>=0.28:../../devel/p5-List-MoreUtils
#DEPENDS+=	p5-Exporter-Tiny-[0-9]*:../../devel/p5-Exporter-Tiny
#DEPENDS+=	p5-Module-Implementation-[0-9]*:../../devel/p5-Module-Implementation
TOOL_DEPENDS+=	p5-Test-LeakTrace-[0-9]*:../../devel/p5-Test-LeakTrace
TOOL_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings

PERL5_PACKLIST=	auto/List/SomeUtils/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
