# $NetBSD: Makefile,v 1.4 2001/11/26 06:49:40 jlam Exp $
#

DISTNAME=		DBD-Sybase-0.23
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dsy
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.mbay.net/~mpeppler/
COMMENT=		perl DBI/DBD driver for Sybase/MS-SQL databases

DEPENDS+=		p5-DBI>=1.13:../../databases/p5-DBI

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBD/Sybase/.packlist

LDFLAGS+=		-Wl,-R${BUILDLINK_PREFIX.freetds}/freetds/lib
MAKE_ENV+=		SYBASE=${BUILDLINK_DIR}/freetds

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

.include "../../databases/freetds/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
