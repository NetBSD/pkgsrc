# $NetBSD: Makefile,v 1.1.1.1 2002/10/06 03:07:03 heinz Exp $
#

DISTNAME=	Digest-Nilsimsa-0.06
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nil
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-Nilsimsa/
COMMENT=	perl5 extension module for Nilsimsa signatures

# _might_ work with earlier version but author says, it was only tested
# with 5.6.1 :-/
BUILDLINK_DEPENDS.perl=	perl>=5.6.1
USE_BUILDLINK2=		YES

PERL5_CONFIGURE=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Digest/Nilsimsa/.packlist

test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKEFLAGS} test

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
