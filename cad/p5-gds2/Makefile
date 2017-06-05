# $NetBSD: Makefile,v 1.5 2017/06/05 14:22:18 ryoon Exp $

DISTNAME=	GDS2-3.33
PKGNAME=	p5-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/S/SC/SCHUMACK/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/GDS2/lib/GDS2.pm
COMMENT=	Modules to read, write, and manipulate GDS2 (GDSII) stream files
LICENSE=	artistic

PERL5_PACKLIST= auto/GDS2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
