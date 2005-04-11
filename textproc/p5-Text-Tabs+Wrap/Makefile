# $NetBSD: Makefile,v 1.3 2005/04/11 21:47:38 tv Exp $

DISTNAME=	Text-Tabs+Wrap-2001.0929
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~muir/${DISTNAME}
COMMENT=	Line wrapping to form simple paragraphs

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Text/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
