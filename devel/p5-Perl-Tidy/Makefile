# $NetBSD: Makefile,v 1.9 2008/06/12 02:14:25 joerg Exp $
#

DISTNAME=	Perl-Tidy-20070508
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pt
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=perltidy/}

MAINTAINER=	adam@migus.org
HOMEPAGE=	http://perltidy.sourceforge.net/
COMMENT=	Parses and beautifies perl source

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Perl/Tidy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
