# $NetBSD: Makefile,v 1.17 2018/08/22 09:44:53 wiz Exp $

DISTNAME=	Tree-Simple-VisitorFactory-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tree/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tree-Simple-VisitorFactory/
COMMENT=	Collection of visitor objects for use with Tree::Simple
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Exception>=0.20:../../devel/p5-Test-Exception
DEPENDS+=	p5-Tree-Simple>=1.22:../../devel/p5-Tree-Simple

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Tree/Simple/VisitorFactory/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
