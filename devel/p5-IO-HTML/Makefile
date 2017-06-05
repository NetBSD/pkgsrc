# $NetBSD: Makefile,v 1.11 2017/06/05 14:23:06 ryoon Exp $

DISTNAME=	IO-HTML-1.001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-HTML/
COMMENT=	Open an HTML file with automatic charset detection
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/IO/HTML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
