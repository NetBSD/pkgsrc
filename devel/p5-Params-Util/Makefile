# $NetBSD: Makefile,v 1.30 2022/06/28 11:33:02 wiz Exp $

DISTNAME=	Params-Util-1.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Params/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Params-Util
COMMENT=	Simple standalone param-checking functions
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Params/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
