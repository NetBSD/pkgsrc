# $NetBSD: Makefile,v 1.74 2023/07/06 09:40:39 wiz Exp $

# Author requests that we package only "production" versions.  See
# https://exiftool.org/history.html for NEWS content and which
# versions are blessed.
DISTNAME=	Image-ExifTool-12.60
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}
MASTER_SITES+=	https://exiftool.org/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://exiftool.org/
#HOMEPAGE_ALT=	https://exiftool.sourceforge.net/
COMMENT=	Perl module and program to read EXIF information
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Image/ExifTool/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
