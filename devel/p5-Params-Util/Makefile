# $NetBSD: Makefile,v 1.32 2023/07/06 09:39:49 wiz Exp $

DISTNAME=	Params-Util-1.102
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Params/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Params-Util
COMMENT=	Simple standalone param-checking functions
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Params/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
