# $NetBSD: Makefile,v 1.11 2004/12/20 11:31:02 grant Exp $
#

DISTNAME=      	Parse-Yapp-1.05
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pya
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 LALR parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Parse/Yapp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
