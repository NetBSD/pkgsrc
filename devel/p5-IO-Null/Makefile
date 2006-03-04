# $NetBSD: Makefile,v 1.9 2006/03/04 21:29:22 jlam Exp $
#

DISTNAME=		IO-Null-0.02
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5inu
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl module for null filehandles

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/IO/Null/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
