# $NetBSD: Makefile,v 1.6 2005/08/06 06:19:13 jlam Exp $
#

DISTNAME=	Perl-Tidy-20031021
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pt
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=perltidy/}

MAINTAINER=	adam@migus.org
HOMEPAGE=	http://perltidy.sourceforge.net/
COMMENT=	Parses and beautifies perl source

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Perl/Tidy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
