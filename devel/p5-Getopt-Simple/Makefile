# $NetBSD: Makefile,v 1.31 2023/07/06 09:39:16 wiz Exp $

DISTNAME=	Getopt-Simple-1.52
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Getopt/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Getopt-Simple
COMMENT=	Simple Getopt wrapper
LICENSE=	artistic

USE_TOOLS+=	perl

PERL5_PACKLIST=		auto/Getopt/Simple/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
