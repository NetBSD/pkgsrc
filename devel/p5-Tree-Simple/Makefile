# $NetBSD: Makefile,v 1.16 2012/10/03 21:55:49 wiz Exp $
#

DISTNAME=	Tree-Simple-1.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tree/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tree-Simple/
COMMENT=	Simple extension to manipulate tree objects

DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils>=1.18}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Test-Exception>=0.20:../../devel/p5-Test-Exception

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Tree/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
