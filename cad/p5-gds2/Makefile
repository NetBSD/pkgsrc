# $NetBSD: Makefile,v 1.12 2020/09/08 13:16:33 wiz Exp $

DISTNAME=	GDS2-3.35
PKGNAME=	p5-${DISTNAME:tl}
PKGREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SC/SCHUMACK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/distribution/GDS2/lib/GDS2.pm
COMMENT=	Modules to read, write, and manipulate GDS2 (GDSII) stream files
LICENSE=	artistic

PERL5_PACKLIST=	auto/GDS2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
