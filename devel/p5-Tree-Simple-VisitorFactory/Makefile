# $NetBSD: Makefile,v 1.19 2019/08/11 13:20:42 wiz Exp $

DISTNAME=	Tree-Simple-VisitorFactory-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tree/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Tree-Simple-VisitorFactory
COMMENT=	Collection of visitor objects for use with Tree::Simple
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Exception>=0.20:../../devel/p5-Test-Exception
DEPENDS+=	p5-Tree-Simple>=1.22:../../devel/p5-Tree-Simple

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Tree/Simple/VisitorFactory/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
