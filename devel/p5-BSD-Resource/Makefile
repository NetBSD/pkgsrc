# $NetBSD: Makefile,v 1.11 2004/11/29 14:04:47 he Exp $

DISTNAME=	BSD-Resource-1.24
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5bsd
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=BSD/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://iki.fi/jhi/
COMMENT=	Perl interface to BSD process resources library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/BSD/Resource/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
