# $NetBSD: Makefile,v 1.20 2023/07/06 09:41:43 wiz Exp $

DISTNAME=	Pod-Eventual-0.094003
PKGNAME=	p5-${DISTNAME:S/094003/094.003/}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Pod-Eventual
COMMENT=	Read a POD document as a series of trivial events
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Mixin-Linewise>=0.102:../../devel/p5-Mixin-Linewise

TOOL_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

PERL5_PACKLIST=		auto/Pod/Eventual/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
