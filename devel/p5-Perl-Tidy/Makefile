# $NetBSD: Makefile,v 1.5 2005/07/13 18:01:28 jlam Exp $
#

DISTNAME=	Perl-Tidy-20031021
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pt
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=perltidy/}

MAINTAINER=	adam@migus.org
HOMEPAGE=	http://perltidy.sourceforge.net/
COMMENT=	Parses and beautifies perl source

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Perl/Tidy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
