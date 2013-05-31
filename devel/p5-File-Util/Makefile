# $NetBSD: Makefile,v 1.7 2013/05/31 12:40:21 wiz Exp $
#

DISTNAME=	File-Util-3.32
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Util/
COMMENT=	Perl extension for easy, versatile, portable file handling
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Exception-Handler>=1:../../devel/p5-Exception-Handler

PERL5_PACKLIST=		auto/File/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
