# $NetBSD: Makefile,v 1.2 2010/08/21 16:34:44 seb Exp $
#

DISTNAME=	XSLoader-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SA/SAPER/}

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://search.cpan.org/dist/XSLoader/
COMMENT=	Dynamically load C libraries into Perl code

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/XSLoader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
