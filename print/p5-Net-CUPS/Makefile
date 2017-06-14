# $NetBSD: Makefile,v 1.25 2017/06/14 21:26:13 wiz Exp $

DISTNAME=	Net-CUPS-0.64
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	print net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-CUPS/
COMMENT=	Common Unix Printing System Interface
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c

PERL5_PACKLIST=	auto/Net/CUPS/.packlist

EXTRACT_USING= bsdtar

BUILDLINK_DEPMETHOD.cups-filters= build # image.h
.include "../../print/cups-filters/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
