# $NetBSD: Makefile,v 1.7 2024/11/16 12:06:41 wiz Exp $

DISTNAME=	Unix-Processors-2.046
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/W/WS/WSNYDER/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Unix::Processors
COMMENT=	Interface to processor (CPU) information
LICENSE=	artistic-2.0

PERL5_PACKLIST=	auto/Unix/Processors/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
