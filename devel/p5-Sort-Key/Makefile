# $NetBSD: Makefile,v 1.2 2018/08/22 09:44:38 wiz Exp $
#

DISTNAME=	Sort-Key-1.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sort/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sort-Key/
COMMENT=	Sort arrays by one or multiple calculated keys
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Sort/Key/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
