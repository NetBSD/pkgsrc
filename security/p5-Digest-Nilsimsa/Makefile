# $NetBSD: Makefile,v 1.8 2004/11/21 14:27:12 kristerw Exp $
#

DISTNAME=	Digest-Nilsimsa-0.06
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nil
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-Nilsimsa/
COMMENT=	Perl5 extension module for Nilsimsa signatures

USE_BUILDLINK3=		YES

PERL5_CONFIGURE=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/Nilsimsa/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
