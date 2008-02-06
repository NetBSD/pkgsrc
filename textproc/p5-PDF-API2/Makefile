# $NetBSD: Makefile,v 1.15 2008/02/06 20:13:57 heinz Exp $

DISTNAME=	PDF-API2-0.69
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PDF-API2/
COMMENT=	Perl5 module for next generation api for pdf

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Compress-Zlib>=1.0:../../devel/p5-Compress-Zlib

PERL5_PACKLIST=	auto/PDF/API2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
