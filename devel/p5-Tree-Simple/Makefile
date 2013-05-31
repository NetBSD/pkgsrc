# $NetBSD: Makefile,v 1.18 2013/05/31 12:40:53 wiz Exp $
#

DISTNAME=	Tree-Simple-1.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tree/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tree-Simple/
COMMENT=	Simple extension to manipulate tree objects

DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils>=1.18}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Test-Exception>=0.20:../../devel/p5-Test-Exception

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Tree/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
