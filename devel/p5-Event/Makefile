# $NetBSD: Makefile,v 1.9 2004/12/20 11:30:59 grant Exp $

DISTNAME=	Event-0.83
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5eve
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JP/JPRIT/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Event library for Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Event/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
