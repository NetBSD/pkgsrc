# $NetBSD: Makefile,v 1.1.1.1 2006/01/31 21:05:59 kleink Exp $

DISTNAME=	XML-Atom-SimpleFeed-0.7
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xas
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Atom-SimpleFeed/
COMMENT=	Generate simple Atom syndication feeds

BUILD_DEPENDS+=	p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple
DEPENDS+=	p5-XML-Simple>=2.10:../../textproc/p5-XML-Simple

PERL5_PACKLIST=		auto/XML/Atom/SimpleFeed/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
