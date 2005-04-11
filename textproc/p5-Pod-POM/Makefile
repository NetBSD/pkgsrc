# $NetBSD: Makefile,v 1.11 2005/04/11 21:47:37 tv Exp $
#

DISTNAME=       Pod-POM-0.14
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5pod
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kfs.org/~abw/
COMMENT=	P5 module to format POD into an object format, hence POM

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Pod/POM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
