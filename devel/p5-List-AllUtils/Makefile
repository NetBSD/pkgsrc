# $NetBSD: Makefile,v 1.7 2013/05/31 12:40:27 wiz Exp $
#

DISTNAME=	List-AllUtils-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=List/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/List-AllUtils/
COMMENT=	Combines List::Util and List::MoreUtils
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/List/AllUtils/.packlist

DEPENDS+=	p5-List-MoreUtils>=0.28:../../devel/p5-List-MoreUtils

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
