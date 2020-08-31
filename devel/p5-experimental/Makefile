# $NetBSD: Makefile,v 1.19 2020/08/31 18:09:16 wiz Exp $

DISTNAME=	experimental-0.022
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LE/LEONT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/experimental
COMMENT=	Replace functions with ones that succeed or die with lexical scope
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/experimental/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
