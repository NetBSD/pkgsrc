# $NetBSD: Makefile,v 1.4 2001/11/28 05:20:45 jlam Exp $

.include "../../databases/postgresql/Makefile.common"
.include "../../databases/postgresql/Makefile.ssl"

PKGNAME=		postgresql-plperl-${PG_VERS}
PG_PKG_VERS=		# empty
COMMENT=		PL/Perl procedural language for the PostgreSQL backend

BUILDLINK_DEPENDS.postgresql-lib=	postgresql-lib>=${PG_BASE_VERS}
DEPENDS+=		postgresql-server>=${PG_BASE_VERS}:../../databases/postgresql-server
DEPENDS+=		libperl>=${LIBPERL5_REQD}:../../lang/libperl

USE_BUILDLINK_ONLY=	YES
LIBPERL5_REQD=		${PERL5_REQD}

CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ENV+=		PERL="${PERL5}"

.if (${OBJECT_FMT} == "ELF")
MAKE_ENV+=		RPATH_LDFLAGS="-Wl,-R${PERL5_ARCHLIB}/CORE"
.else
MAKE_ENV+=		RPATH_LDFLAGS="-R${PERL5_ARCHLIB}/CORE"
.endif

DIRS_TO_BUILD=		src/pl/plperl

do-build:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${ALL_TARGET}
.endfor

do-install:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}
.endfor

.include "../../databases/postgresql-lib/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
