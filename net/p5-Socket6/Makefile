# $NetBSD: Makefile,v 1.2 2000/05/26 14:59:57 itojun Exp $
#

DISTNAME=		Socket6-0.06
PKGNAME=		p5-Socket6-0.06
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Socket6/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/libnet/FAQ.html

USE_PERL5=		YES

# supports IPv6 (actually, af independent)
.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=	USE_INET6

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL \
		CCFLAGS="${CFLAGS} ${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
