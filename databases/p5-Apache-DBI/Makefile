# $NetBSD: Makefile,v 1.1.1.1 2002/06/16 20:43:10 wiz Exp $
#

DISTNAME=	ApacheDBI-0.88
PKGNAME=	p5-Apache-DBI-0.88
SVR4_PKGNAME=	p5adb
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.symbolstone.org/technology/perl/DBI/index.html
COMMENT=	DBI support for Apache+mod_perl

DEPENDS+=		p5-DBI>=1.13:../../databases/p5-DBI

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/DBI/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
