# $NetBSD: Makefile,v 1.1.1.1 2005/11/04 16:53:08 gdt Exp $

DISTNAME=	Image-ExifTool-${VERSION}
PKGNAME=	exiftool-${VERSION}
CATEGORIES=	graphics perl5
MASTER_SITES=	http://owl.phy.queensu.ca/~phil/exiftool/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://owl.phy.queensu.ca/~phil/exiftool/
COMMENT=	Perl module and program to read EXIF information

VERSION=	5.72

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Image/ExifTool/.packlist

REPLACE_PERL=	exiftool

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
