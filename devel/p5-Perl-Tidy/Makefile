# $NetBSD: Makefile,v 1.18 2012/10/03 21:55:29 wiz Exp $
#

DISTNAME=	Perl-Tidy-20120714
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5pt
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=perltidy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perltidy.sourceforge.net/
#HOMEPAGE=	http://search.cpan.org/dist/Perl-Tidy/
COMMENT=	Parses and beautifies perl source
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Perl/Tidy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
