# $NetBSD: Makefile,v 1.3 1999/12/28 12:53:10 wiz Exp $
#

DISTNAME=	Digest-MD5-2.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	packages@netbsd.org

CONFLICTS+=	p5-MD5-*

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
