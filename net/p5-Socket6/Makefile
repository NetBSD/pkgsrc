# $NetBSD: Makefile,v 1.54 2023/07/06 09:41:15 wiz Exp $

DISTNAME=		Socket6-0.29
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Socket6/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Socket6
COMMENT=		Perl5 module to support getaddrinfo() and getnameinfo()
LICENSE=		modified-bsd

PERL5_PACKLIST=		auto/Socket6/.packlist

# supports IPv6 (actually, AF-independent)
BUILD_DEFS+=		IPV6_READY

USE_LANGUAGES=		c
MAKE_ENV+=		CCFLAGS="${CFLAGS} ${CPPFLAGS}"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "AIX" && ${PKGSRC_COMPILER:Mxlc}
MAKE_ENV+=		CC="cc_r"
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
