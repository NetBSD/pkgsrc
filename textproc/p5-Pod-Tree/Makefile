# $NetBSD: Makefile,v 1.2 2006/03/04 21:30:48 jlam Exp $

DISTNAME=	Pod-Tree-1.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Tree/
COMMENT=	Create a static syntax tree for a POD

BUILD_DEPENDS+=	p5-HTML-Stream>=1.49:../../www/p5-HTML-Stream
DEPENDS+=	p5-Pod-Escapes>=1.02:../../textproc/p5-Pod-Escapes

PERL5_PACKLIST=	auto/Pod/Tree/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
