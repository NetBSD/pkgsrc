# $NetBSD: Makefile,v 1.10 2004/12/20 11:31:09 grant Exp $
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

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Pod/POM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
