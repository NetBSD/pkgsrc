# $NetBSD: Makefile,v 1.54 2026/10/05 01:56:17 wen Exp $

DISTNAME=	IO-Tty-1.31
PKGNAME=	p5-${DISTNAME:C/T/t/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TO/TODDR/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IO-Tty
COMMENT=	Another Perl class for I/O on tty and pseudo-tty devices
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/IO/Tty/.packlist

BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--no-undefined

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
