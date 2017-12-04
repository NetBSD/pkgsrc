# $NetBSD: Makefile,v 1.12 2017/12/04 07:40:38 wiz Exp $

DISTNAME=	experimental-0.019
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LE/LEONT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/experimental/
COMMENT=	Replace functions with ones that succeed or die with lexical scope
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/experimental/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
