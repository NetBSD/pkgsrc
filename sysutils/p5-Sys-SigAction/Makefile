# $NetBSD: Makefile,v 1.25 2026/07/16 19:04:56 wiz Exp $

DISTNAME=	Sys-SigAction-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sys/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sys-SigAction
COMMENT=	Perl extension for Consistent Signal Handling
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Sys/SigAction/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
