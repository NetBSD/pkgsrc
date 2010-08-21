# $NetBSD: Makefile,v 1.14 2010/08/21 16:33:49 seb Exp $

DISTNAME=	Getopt-Simple-1.49
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Getopt/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Getopt-Simple/
COMMENT=	Simple Getopt wrapper

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl

PERL5_PACKLIST=	auto/Getopt/Simple/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
