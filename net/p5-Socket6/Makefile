# $NetBSD: Makefile,v 1.5 2001/01/30 19:36:04 itojun Exp $
#

DISTNAME=		Socket6-0.08
PKGNAME=		p5-Socket6-0.08
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Socket6/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/libnet/FAQ.html

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Socket6/.packlist

.include "../../mk/bsd.prefs.mk"

# supports IPv6 (actually, af independent)
BUILD_DEFS+=		USE_INET6

MAKE_ENV+=		CCFLAGS="${CFLAGS} ${CPPFLAGS}"

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
