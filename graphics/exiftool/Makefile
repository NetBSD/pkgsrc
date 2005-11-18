# $NetBSD: Makefile,v 1.3 2005/11/18 14:41:24 gdt Exp $

DISTNAME=	Image-ExifTool-${VERSION}
PKGNAME=	exiftool-${VERSION}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/} \
		http://owl.phy.queensu.ca/~phil/exiftool/

MAINTAINER=	gdt@NetBSD.org
# author says www.sno is the same machine, but was never advertised
HOMEPAGE=	http://owl.phy.queensu.ca/~phil/exiftool/
COMMENT=	Perl module and program to read EXIF information

# author requests that we package "production" versions
VERSION=	5.77

PERL5_PACKLIST=	auto/Image/ExifTool/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
