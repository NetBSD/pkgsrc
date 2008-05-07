# $NetBSD: Makefile,v 1.14 2008/05/07 19:52:54 gdt Exp $

DISTNAME=	Image-ExifTool-${VERSION}
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/} \
		http://owl.phy.queensu.ca/~phil/exiftool/

MAINTAINER=	gdt@NetBSD.org
# author says www.sno is the same machine, but was never advertised
HOMEPAGE=	http://owl.phy.queensu.ca/~phil/exiftool/
COMMENT=	Perl module and program to read EXIF information

# Author requests that we package only "production" versions.
VERSION=	7.25

PERL5_PACKLIST=	auto/Image/ExifTool/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
