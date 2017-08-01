# $NetBSD: Makefile,v 1.1 2017/08/01 13:02:57 markd Exp $
#

DISTNAME=	List-MoreUtils-XS-0.418
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=List/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/List-MoreUtils-XS/
COMMENT=	Provide compiled List::MoreUtils functions
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-List-MoreUtils>=0.417:../../devel/p5-List-MoreUtils

PERL5_PACKLIST=		auto/List/MoreUtils/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
