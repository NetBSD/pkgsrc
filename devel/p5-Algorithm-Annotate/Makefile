# $NetBSD: Makefile,v 1.2 2004/04/25 04:20:01 minskim Exp $

DISTNAME=	Algorithm-Annotate-0.10
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ext
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module that provides cvs-annotate-like functionality

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Algorithm/Annotate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
