# $NetBSD: Makefile,v 1.6 2003/07/17 21:32:55 grant Exp $
#

DISTNAME=      	Tie-IxHash-1.21
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tix
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module that implements ordered in-memory associative arrays

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Tie/IxHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
