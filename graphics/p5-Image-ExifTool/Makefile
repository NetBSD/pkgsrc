# $NetBSD: Makefile,v 1.24 2010/02/10 15:27:57 gdt Exp $

DISTNAME=	Image-ExifTool-${VERSION}
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/} \
		http://owl.phy.queensu.ca/~phil/exiftool/

MAINTAINER=	gdt@NetBSD.org
# author says www.sno is the same machine, but was never advertised
HOMEPAGE=	http://owl.phy.queensu.ca/~phil/exiftool/
COMMENT=	Perl module and program to read EXIF information

PKG_DESTDIR_SUPPORT=	user-destdir

# Author requests that we package only "production" versions.
VERSION=	8.10

PERL5_PACKLIST=	auto/Image/ExifTool/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
