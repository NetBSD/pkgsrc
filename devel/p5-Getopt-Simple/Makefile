# $NetBSD: Makefile,v 1.1.1.1 2004/02/24 03:01:45 minskim Exp $

DISTNAME=	Getopt-Simple-1.46
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Getopt/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://search.cpan.org/~rsavage/Getopt-Simple-1.46/Simple.pm
COMMENT=	Simple Getopt wrapper

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Getopt/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
