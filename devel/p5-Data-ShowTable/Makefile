# $NetBSD: Makefile,v 1.13 2006/07/12 11:36:12 rillig Exp $
#

DISTNAME=		Data-ShowTable-3.3
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dst
PKGREVISION=		3
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=		bad@NetBSD.org
COMMENT=		Perl module to print arrays of data in nicely formatted listings

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Data/ShowTable/.packlist
REPLACE_PERL+=		showtable

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
