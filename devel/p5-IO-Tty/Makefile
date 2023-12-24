# $NetBSD: Makefile,v 1.49 2023/12/24 01:16:17 schmonz Exp $

DISTNAME=	IO-Tty-1.18
PKGNAME=	p5-${DISTNAME:C/T/t/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IO-Tty
COMMENT=	Another Perl class for I/O on tty and pseudo-tty devices
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/IO/Tty/.packlist

BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--no-undefined

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
