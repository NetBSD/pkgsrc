# $NetBSD: Makefile,v 1.2 2004/04/25 04:18:44 minskim Exp $

DISTNAME=	Algorithm-Merge-0.04
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ext
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module providing diff3(1)-like functionality

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Algorithm/Merge/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
