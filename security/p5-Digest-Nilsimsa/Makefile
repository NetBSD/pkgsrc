# $NetBSD: Makefile,v 1.4 2003/07/17 22:53:07 grant Exp $
#

DISTNAME=	Digest-Nilsimsa-0.06
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nil
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-Nilsimsa/
COMMENT=	perl5 extension module for Nilsimsa signatures

# _might_ work with earlier version but author says, it was only tested
# with 5.6.1 :-/
BUILDLINK_DEPENDS.perl=	perl>=5.6.1
USE_BUILDLINK2=		YES
TEST_TARGET=		test

PERL5_CONFIGURE=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/Nilsimsa/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
