# $NetBSD: Makefile,v 1.6 2002/09/09 00:22:22 heinz Exp $
#

DISTNAME=		Net-DNS-0.28
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ndn
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}		\
			http://www.net-dns.org/download/

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.net-dns.org/
COMMENT=		Net::DNS - Perl DNS Resolver Module

BUILD_DEPENDS+=		p5-Test-Simple>=0.44:../../devel/p5-Test-Simple

DEPENDS+=		p5-Digest-HMAC>=1.0:../../security/p5-Digest-HMAC
DEPENDS+=		p5-MIME-Base64>=2.11:../../converters/p5-MIME-Base64

BUILDLINK_DEPENDS.perl=	perl>=5.005_03

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/DNS/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKEFLAGS} test

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
