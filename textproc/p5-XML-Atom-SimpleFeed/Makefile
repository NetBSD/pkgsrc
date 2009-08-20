# $NetBSD: Makefile,v 1.10 2009/08/20 17:47:21 sno Exp $

DISTNAME=	XML-Atom-SimpleFeed-0.86
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xas
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Atom-SimpleFeed/
COMMENT=	Generate simple Atom syndication feeds
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/XML/Atom/SimpleFeed/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
