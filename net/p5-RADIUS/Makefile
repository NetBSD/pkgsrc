# $NetBSD: Makefile,v 1.3 2004/12/20 11:31:07 grant Exp $
#

DISTNAME=	RADIUS-1.0
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5rad
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=RADIUS/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.netmonger.net/~chris/RADIUS/
COMMENT=	Perl5 module for RADIUS queries

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/RADIUS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
