# $NetBSD: Makefile,v 1.16 2007/02/22 19:27:15 wiz Exp $
#

DISTNAME=	Pod-POM-0.17
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pod
# PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kfs.org/~abw/
COMMENT=	P5 module to format POD into an object format, hence POM

PERL5_PACKLIST=		auto/Pod/POM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
