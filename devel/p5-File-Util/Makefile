# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:06 obache Exp $
#

DISTNAME=	File-Util-3.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Util/
COMMENT=	Perl extension for easy, versatile, portable file handling
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-OOorNO>=0.01:../../devel/p5-Class-OOorNO
DEPENDS+=	p5-Exception-Handler>=1:../../devel/p5-Exception-Handler

PERL5_PACKLIST=		auto/File/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
