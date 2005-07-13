# $NetBSD: Makefile,v 1.11 2005/07/13 18:01:24 jlam Exp $
#

DISTNAME=		Data-ShowTable-3.3
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dst
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=		bad@NetBSD.org
COMMENT=		Perl module to print arrays of data in nicely formatted listings

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Data/ShowTable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
