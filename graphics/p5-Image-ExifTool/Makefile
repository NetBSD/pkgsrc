# $NetBSD: Makefile,v 1.80 2024/12/24 10:58:48 wiz Exp $

# Author requests that we package only "production" versions.  See
# https://exiftool.org/history.html for NEWS content and which
# versions are blessed.   Note that repology gets this wrong.
DISTNAME=	Image-ExifTool-13.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}
MASTER_SITES+=	https://exiftool.org/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://exiftool.org/
#HOMEPAGE_ALT=	https://exiftool.sourceforge.net/
COMMENT=	Perl module and program to read EXIF information
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Image/ExifTool/.packlist

REPLACE_PERL+=	exiftool

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
