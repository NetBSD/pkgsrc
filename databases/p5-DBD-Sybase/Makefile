# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 18:47:59 rh Exp $
#

DISTNAME=		DBD-Sybase-0.23
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.mbay.net/~mpeppler/

DEPENDS+=		freetds>=0.50:../../databases/freetds
DEPENDS+=		p5-DBI>=1.13:../../databases/p5-DBI

USE_PERL5=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBD/Sybase/.packlist

MAKE_ENV+=		SYBASE=${PREFIX}/freetds
MAKE_PARAMS+=		--noprompt

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

.include "../../mk/bsd.pkg.mk"
