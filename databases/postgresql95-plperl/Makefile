#$ $NetBSD: Makefile,v 1.2 2016/03/05 11:28:18 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/95-plperl-/}
PKGREVISION=	1
COMMENT=	PL/Perl procedural language for the PostgreSQL backend

DEPENDS+=	postgresql95-server>=${PKGVERSION_NOREV}:../../databases/postgresql95-server

.include "../../databases/postgresql95/Makefile.common"

USE_TOOLS+=		perl
PERL5_CONFIGURE=	no
CONFIGURE_ARGS+=	--with-perl
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/plperl
MAKE_FILE=		GNUmakefile

# There is some dependency ordering problem in the Makefile,
# so force the headers to be generated first.
BUILD_TARGET=		perlchunks.h plperl_opmask.h all

#.PHONY: build-hstore_plperl
#post-build: build-hstore_plperl
#build-hstore_plperl:
#	cd ${WRKSRC}/contrib/hstore_plperl &&	\
#		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} -f Makefile all

.include "../../databases/postgresql95-client/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
