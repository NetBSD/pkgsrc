# $NetBSD: Makefile,v 1.6 2005/05/16 03:04:45 jlam Exp $

DISTNAME=	Getopt-Simple-1.48
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Getopt/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://search.cpan.org/~rsavage/Getopt-Simple/
COMMENT=	Simple Getopt wrapper

PKG_INSTALLATION_TYPES=	overwrite pkgviews

EXTRACT_USING=	pax

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Getopt/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
