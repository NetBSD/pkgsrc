# $NetBSD: Makefile,v 1.14 2005/12/04 12:25:49 mjl Exp $
#

DISTNAME=       Pod-POM-0.17
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5pod
# PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kfs.org/~abw/
COMMENT=	P5 module to format POD into an object format, hence POM

PERL5_PACKLIST=		auto/Pod/POM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
