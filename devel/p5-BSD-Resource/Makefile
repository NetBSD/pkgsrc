# $NetBSD: Makefile,v 1.13 2005/02/11 18:07:50 tv Exp $

DISTNAME=	BSD-Resource-1.24
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5bsd
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=BSD/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://iki.fi/jhi/
COMMENT=	Perl interface to BSD process resources library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/BSD/Resource/.packlist

post-extract:
	${RM} -f ${WRKSRC}/t/[gs]etpriority.t

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
