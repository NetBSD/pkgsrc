# $NetBSD: Makefile,v 1.7 2002/09/20 02:51:00 grant Exp $
#

DISTNAME=		DBD-Sybase-0.94
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dsy
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.mbay.net/~mpeppler/
COMMENT=		perl DBI/DBD driver for Sybase/MS-SQL databases

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBD/Sybase/.packlist

LDFLAGS+=		-Wl,-R${BUILDLINK_PREFIX.freetds}/freetds/lib
MAKE_ENV+=		SYBASE=${BUILDLINK_PREFIX.freetds}/freetds

.include "../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "a.out"
MAKE_FLAGS+=		OTHERLDFLAGS="${LDFLAGS:S/-Wl,//g}"
.else
MAKE_FLAGS+=		OTHERLDFLAGS="${LDFLAGS}"
.endif

do-configure:
	@cd ${WRKSRC}; \
	( \
		${ECHO_MSG} "undef" ; \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "undef" ; \
	) | ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

.include "../../databases/freetds/buildlink2.mk"
.include "../../databases/p5-DBI/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
