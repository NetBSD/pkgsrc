# $NetBSD: Makefile,v 1.1.1.1 1998/11/26 18:16:05 bad Exp $
#

DISTNAME=		Devel-SmallProf-0.5
PKGNAME=		p5-Devel-SmallProf-0.5
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel

MAINTAINER=		bad@netbsd.org

DEPENDS=		p5-Time-HiRes-01.19:../../devel/p5-Time-HiRes

USE_PERL5=		yes

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
