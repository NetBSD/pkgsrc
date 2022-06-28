# $NetBSD: Makefile,v 1.7 2022/06/28 11:33:13 wiz Exp $
#

DISTNAME=	Sort-Key-1.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sort/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sort-Key
COMMENT=	Sort arrays by one or multiple calculated keys
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Sort/Key/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
