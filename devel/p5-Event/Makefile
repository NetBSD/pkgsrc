# $NetBSD: Makefile,v 1.8 2004/01/05 22:16:25 jlam Exp $

DISTNAME=	Event-0.83
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5eve
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JP/JPRIT/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Event library for Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Event/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
