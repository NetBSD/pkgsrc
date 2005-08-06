# $NetBSD: Makefile,v 1.6 2005/08/06 06:19:28 jlam Exp $
#

DISTNAME=	RADIUS-1.0
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5rad
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=RADIUS/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.netmonger.net/~chris/RADIUS/
COMMENT=	Perl5 module for RADIUS queries

PERL5_PACKLIST=		auto/RADIUS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
