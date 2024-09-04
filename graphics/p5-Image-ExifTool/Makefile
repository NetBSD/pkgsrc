# $NetBSD: Makefile,v 1.77 2024/09/04 17:45:59 gdt Exp $

# Author requests that we package only "production" versions.  See
# https://exiftool.org/history.html for NEWS content and which
# versions are blessed.   Note that repology gets this wrong.
DISTNAME=	Image-ExifTool-12.76
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

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
