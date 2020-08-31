# $NetBSD: Makefile,v 1.42 2020/08/31 18:08:12 wiz Exp $

DISTNAME=	IO-Tty-1.14
PKGNAME=	p5-${DISTNAME:C/T/t/}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IO-Tty
COMMENT=	Another Perl class for I/O on tty and pseudo-tty devices
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/IO/Tty/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
