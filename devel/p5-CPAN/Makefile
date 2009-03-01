# $NetBSD: Makefile,v 1.2 2009/03/01 23:07:41 sno Exp $

DISTNAME=	CPAN-1.9304
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/${DISTNAME}/
COMMENT=	Perl module to query, download and build perl modules from CPAN sites

MAKE_PARAMS+=	verbose

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/CPAN/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
