# $NetBSD: Makefile,v 1.1.1.1 2005/11/19 12:47:13 rillig Exp $

DISTNAME=	Pod-Tree-1.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Tree/
COMMENT=	Create a static syntax tree for a POD

BUILD_DEPENDS+=	p5-HTML-Stream>=1.49:../../www/p5-HTML-Stream
DEPENDS+=	p5-Pod-Escapes>=1.02:../../textproc/p5-Pod-Escapes

PERL5_PACKLIST=	auto/Pod/Tree/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
