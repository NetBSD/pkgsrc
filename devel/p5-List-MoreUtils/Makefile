# $NetBSD: Makefile,v 1.15 2014/05/29 23:36:01 wiz Exp $
#

DISTNAME=	List-MoreUtils-0.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=List/}
MASTER_SITES+=	${MASTER_SITE_PERL_CPAN:=../../authors/id/V/VP/VPARSEVAL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/List-MoreUtils/
COMMENT=	Provide the stuff missing in List::Util
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/List/MoreUtils/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
