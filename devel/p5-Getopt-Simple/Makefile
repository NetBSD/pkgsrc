# $NetBSD: Makefile,v 1.10 2008/05/25 21:01:04 joerg Exp $

DISTNAME=	Getopt-Simple-1.48
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Getopt/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~rsavage/Getopt-Simple/
COMMENT=	Simple Getopt wrapper

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Getopt/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
