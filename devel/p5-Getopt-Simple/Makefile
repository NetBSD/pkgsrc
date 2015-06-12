# $NetBSD: Makefile,v 1.22 2015/06/12 10:49:17 wiz Exp $

DISTNAME=	Getopt-Simple-1.52
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Getopt/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Getopt-Simple/
COMMENT=	Simple Getopt wrapper
LICENSE=	artistic

USE_TOOLS+=	perl

PERL5_PACKLIST=		auto/Getopt/Simple/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
