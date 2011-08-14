# $NetBSD: Makefile,v 1.5 2011/08/14 12:26:47 obache Exp $

DISTNAME=	Tree-Simple-VisitorFactory-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5trs
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tree/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tree-Simple-VisitorFactory/
COMMENT=	Collection of visitor objects for use with Tree::Simple

DEPENDS+=	p5-Test-Exception>=0.20:../../devel/p5-Test-Exception
DEPENDS+=	p5-Tree-Simple>=1.00:../../devel/p5-Tree-Simple

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Tree/Simple/VisitorFactory/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
