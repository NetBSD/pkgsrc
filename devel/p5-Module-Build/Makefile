# $NetBSD: Makefile,v 1.5 2005/02/19 12:40:47 wiz Exp $
#

DISTNAME=	Module-Build-0.2608
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mob
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Build/
COMMENT=	Build and install Perl modules

DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PERL5} Build.PL

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build

do-test:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build test

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build install

.include "../../mk/bsd.pkg.mk"
