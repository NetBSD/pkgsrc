# $NetBSD: Makefile,v 1.7 2002/07/22 22:00:51 jlam Exp $

PKGNAME=		postgresql-plperl-${BASE_VERS}
COMMENT=		PL/Perl procedural language for the PostgreSQL backend

DEPENDS+=		postgresql-server>=${BASE_VERS}:../../databases/postgresql-server
DEPENDS+=		{libperl>=${LIBPERL5_REQD},perl>=5.8.0}:../../lang/libperl

LIBPERL5_REQD=		${PERL5_REQD}
USE_BUILDLINK_ONLY=	YES

.include "../../databases/postgresql/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ENV+=		PERL="${PERL5}"

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
