# $NetBSD: Makefile,v 1.9 2002/10/20 17:46:01 seb Exp $
#

DISTNAME=		Socket6-0.08
PKGNAME=		p5-Socket6-0.08
SVR4_PKGNAME=		p5so6
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Socket6/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/libnet/FAQ.html
COMMENT=		perl5 module to support getaddrinfo() and getnameinfo()

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Socket6/.packlist

# supports IPv6 (actually, af independent)
BUILD_DEFS+=		USE_INET6

MAKE_ENV+=		CCFLAGS="${CFLAGS} ${CPPFLAGS}"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
