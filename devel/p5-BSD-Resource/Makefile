# $NetBSD: Makefile,v 1.8 2003/10/31 19:09:14 reed Exp $

DISTNAME=	BSD-Resource-1.15
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5bsd
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=BSD/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://iki.fi/jhi/
COMMENT=	Perl interface to BSD process resources library

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/BSD/Resource/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
