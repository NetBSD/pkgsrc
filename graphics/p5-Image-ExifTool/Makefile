# $NetBSD: Makefile,v 1.61 2018/08/22 09:45:16 wiz Exp $

# Author requests that we package only "production" versions.
# Check http://owl.phy.queensu.ca/~phil/exiftool/history.html
DISTNAME=	Image-ExifTool-11.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
