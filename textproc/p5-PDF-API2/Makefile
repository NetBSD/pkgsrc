# $NetBSD: Makefile,v 1.18 2008/11/18 17:28:29 he Exp $

DISTNAME=	PDF-API2-0.72
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AR/AREIBENS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PDF-API2/
COMMENT=	Perl5 module for next generation api for pdf

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Compress-Zlib>=1.0:../../devel/p5-Compress-Zlib

PERL5_PACKLIST=	auto/PDF/API2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
