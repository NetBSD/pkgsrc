# $NetBSD: Makefile,v 1.9 2014/05/29 23:36:01 wiz Exp $
#

DISTNAME=	List-AllUtils-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=List/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/List-AllUtils/
COMMENT=	Combines List::Util and List::MoreUtils
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/List/AllUtils/.packlist

DEPENDS+=	p5-List-MoreUtils>=0.28:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Scalar-List-Utils>=1.31:../../devel/p5-Scalar-List-Utils

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
