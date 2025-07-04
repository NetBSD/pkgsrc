# $NetBSD: Makefile,v 1.40 2025/07/04 08:45:57 wiz Exp $

DISTNAME=	IO-Stty-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl class for I/O on tty devices
HOMEPAGE=	https://metacpan.org/release/IO-Stty
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	#empty

PERL5_PACKLIST=		auto/IO/Stty/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
