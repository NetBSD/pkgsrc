# $NetBSD: Makefile,v 1.1.1.1 2009/02/09 03:18:07 dsainty Exp $
#

DISTNAME=	Roman-1.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Roman/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Conversion of numeric notation between Roman and Arabic

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Roman/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
