# $NetBSD: Makefile,v 1.10 2008/10/19 19:17:58 he Exp $
#

DISTNAME=	Perl-Tidy-20070508
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
