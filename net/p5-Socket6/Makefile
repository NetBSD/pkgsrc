# $NetBSD: Makefile,v 1.16 2004/06/26 22:02:12 adrianp Exp $
#

DISTNAME=		Socket6-0.17
PKGNAME=		p5-Socket6-0.17
SVR4_PKGNAME=		p5so6
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Socket6/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/libnet/FAQ.html
COMMENT=		Perl5 module to support getaddrinfo() and getnameinfo()

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Socket6/.packlist

# supports IPv6 (actually, af independent)
BUILD_DEFS+=		USE_INET6

MAKE_ENV+=		CCFLAGS="${CFLAGS} ${CPPFLAGS}"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
