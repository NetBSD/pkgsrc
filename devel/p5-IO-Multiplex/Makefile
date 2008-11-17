# $NetBSD: Makefile,v 1.9 2008/11/17 02:58:42 he Exp $
#

DISTNAME=		IO-Multiplex-1.10
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5imx
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/IO-Multiplex/
COMMENT=		Perl module to manage IO on many file handles

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/IO/Multiplex/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
