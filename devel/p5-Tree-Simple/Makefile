# $NetBSD: Makefile,v 1.9 2006/03/04 21:29:25 jlam Exp $
#

DISTNAME=	Tree-Simple-1.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tree/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tree-Simple/
COMMENT=	Simple extension to manipulate tree objects

DEPENDS+=	p5-Scalar-List-Utils>=0.18:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Test-Exception>=0.20:../../devel/p5-Test-Exception

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Tree/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
