# $NetBSD: Makefile,v 1.9 2005/02/19 18:33:11 wiz Exp $
#

DISTNAME=      	Tie-IxHash-1.21
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tix
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-IxHash/
COMMENT=	Perl module that implements ordered in-memory associative arrays

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Tie/IxHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
