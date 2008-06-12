# $NetBSD: Makefile,v 1.17 2008/06/12 02:14:48 joerg Exp $
#

DISTNAME=	PDF-Create-0.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pcr
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	Perl5 module for creating pdf documents

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/PDF/Create/.packlist

REPLACE_PERL=	sample.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
