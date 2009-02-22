# $NetBSD: Makefile,v 1.2 2009/02/22 13:21:32 he Exp $
#

DISTNAME=	Roman-1.23
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Roman/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Roman/
COMMENT=	Conversion of numeric notation between Roman and Arabic

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Roman/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
