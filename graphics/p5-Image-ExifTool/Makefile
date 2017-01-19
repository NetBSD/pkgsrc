# $NetBSD: Makefile,v 1.55 2017/01/19 18:52:12 agc Exp $

# Author requests that we package only "production" versions.
# Check http://owl.phy.queensu.ca/~phil/exiftool/history.html
DISTNAME=	Image-ExifTool-10.40
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}
MASTER_SITES+=	http://owl.phy.queensu.ca/~phil/exiftool/

MAINTAINER=	gdt@NetBSD.org
# author says www.sno is the same machine, but was never advertised
HOMEPAGE=	http://owl.phy.queensu.ca/~phil/exiftool/
COMMENT=	Perl module and program to read EXIF information
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Image/ExifTool/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
