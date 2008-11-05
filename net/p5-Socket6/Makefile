# $NetBSD: Makefile,v 1.29 2008/11/05 15:25:34 wiz Exp $
#

DISTNAME=		Socket6-0.23
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5so6
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Socket6/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Socket6/
COMMENT=		Perl5 module to support getaddrinfo() and getnameinfo()

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Socket6/.packlist

# supports IPv6 (actually, AF-independent)
BUILD_DEFS+=		IPV6_READY

USE_LANGUAGES=		c
MAKE_ENV+=		CCFLAGS="${CFLAGS} ${CPPFLAGS}"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
