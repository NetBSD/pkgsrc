# $NetBSD: Makefile,v 1.4 2005/04/11 21:45:29 tv Exp $

DISTNAME=	Algorithm-Annotate-0.10
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ext
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module that provides cvs-annotate-like functionality

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Algorithm/Annotate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
