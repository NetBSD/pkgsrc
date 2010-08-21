# $NetBSD: Makefile,v 1.22 2010/08/21 16:35:55 seb Exp $

DISTNAME=	PDF-API2-0.73
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AR/AREIBENS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PDF-API2/
COMMENT=	Perl5 module for next generation api for pdf

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-IO-Compress>=2.017:../../devel/p5-IO-Compress

PERL5_PACKLIST=	auto/PDF/API2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
