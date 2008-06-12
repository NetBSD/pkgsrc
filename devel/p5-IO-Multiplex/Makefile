# $NetBSD: Makefile,v 1.6 2008/06/12 02:14:22 joerg Exp $
#

DISTNAME=		IO-Multiplex-1.08
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5imx
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl module to manage IO on many file handles

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/IO/Multiplex/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
