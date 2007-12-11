# $NetBSD: Makefile,v 1.11 2007/12/11 12:04:03 rhaen Exp $
#

DISTNAME=	Tree-Simple-1.18
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tree/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tree-Simple/
COMMENT=	Simple extension to manipulate tree objects

DEPENDS+=	p5-Scalar-List-Utils>=0.18:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Test-Exception>=0.20:../../devel/p5-Test-Exception

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Tree/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
