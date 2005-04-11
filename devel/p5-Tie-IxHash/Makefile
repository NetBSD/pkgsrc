# $NetBSD: Makefile,v 1.10 2005/04/11 21:45:35 tv Exp $
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

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Tie/IxHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
