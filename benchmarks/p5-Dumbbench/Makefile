# $NetBSD: Makefile,v 1.2 2018/08/22 09:42:58 wiz Exp $

DISTNAME=	Dumbbench-0.111
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BD/BDFOY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Dumbbench
COMMENT=	More reliable benchmarking with the least amount of thinking
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Class-XSAccessor-[0-9]*:../../devel/p5-Class-XSAccessor
DEPENDS+=	p5-Devel-CheckOS-[0-9]*:../../devel/p5-Devel-CheckOS
DEPENDS+=	p5-Params-Util-[0-9]*:../../devel/p5-Params-Util
DEPENDS+=	p5-Number-WithError-[0-9]*:../../math/p5-Number-WithError
DEPENDS+=	p5-Statistics-CaseResampling-[0-9]*:../../math/p5-Statistics-CaseResampling

PERL5_PACKLIST=		auto/Dumbbench/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
