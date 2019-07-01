# $NetBSD: Makefile,v 1.9 2019/07/01 21:35:32 nia Exp $

DISTNAME=	GDS2-3.35
PKGNAME=	p5-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/S/SC/SCHUMACK/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/distribution/GDS2/lib/GDS2.pm
COMMENT=	Modules to read, write, and manipulate GDS2 (GDSII) stream files
LICENSE=	artistic

PERL5_PACKLIST=	auto/GDS2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
