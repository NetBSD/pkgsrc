# $NetBSD: Makefile,v 1.20 2008/08/17 05:09:38 dholland Exp $
#

DISTNAME=	PDF-Create-1.02
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pcr
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PDF-Create/
COMMENT=	Perl5 module for creating pdf documents

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/PDF/Create/.packlist

REPLACE_PERL=	sample.pl sample-cgi.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
