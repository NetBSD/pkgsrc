# $NetBSD: Makefile,v 1.6 2009/09/22 17:19:51 sno Exp $
#

DISTNAME=	AutoLoader-5.70
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5aul
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AutoLoader/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AutoLoader/
COMMENT=	Perl automatic module loader
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/AutoLoader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
