# $NetBSD: Makefile,v 1.22 2010/08/21 16:35:56 seb Exp $
#

DISTNAME=	PDF-Create-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5pcr
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
