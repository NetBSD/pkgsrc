# $NetBSD: Makefile,v 1.26 2010/07/13 06:37:34 adam Exp $

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
VERSION=	8.24

PERL5_PACKLIST=	auto/Image/ExifTool/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
