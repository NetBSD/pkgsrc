# $NetBSD: Makefile,v 1.7 2011/08/09 07:33:08 adam Exp $

DISTNAME=	enum-1.016
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=enum/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/enum/
COMMENT=	Enumerations for Perl
#LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/enum/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
