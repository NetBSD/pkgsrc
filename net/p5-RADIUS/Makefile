# $NetBSD: Makefile,v 1.1.1.1 2003/09/10 14:34:37 cjep Exp $
#

DISTNAME=	RADIUS-1.0
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5rad
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=RADIUS/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.netmonger.net/~chris/RADIUS/
COMMENT=	Perl5 module for RADIUS queries

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/RADIUS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
