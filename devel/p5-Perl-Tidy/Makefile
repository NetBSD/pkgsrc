# $NetBSD: Makefile,v 1.11 2008/12/18 23:22:21 he Exp $
#

DISTNAME=	Perl-Tidy-20071205
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pt
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=perltidy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perltidy.sourceforge.net/
#HOMEPAGE=	http://search.cpan.org/dist/Perl-Tidy/
COMMENT=	Parses and beautifies perl source

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Perl/Tidy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
