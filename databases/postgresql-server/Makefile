# $NetBSD: Makefile,v 1.24 2002/10/19 03:03:51 jlam Exp $

PKGNAME=		postgresql-server-${BASE_VERS}
COMMENT=		PostgreSQL database server programs

DEPENDS+=		postgresql-client>=${BASE_VERS}:../../databases/postgresql-client

# mips has no TAS implementation
NOT_FOR_PLATFORM=	*-*-mips

USE_BUILDLINK2=		# defined

.include "../../databases/postgresql/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
BUILD_DIRS=		${WRKSRC}/src/backend

.if defined(USE_PAM)
.  include "../../security/PAM/buildlink2.mk"
CONFIGURE_ARGS+=	--with-pam
.endif

# PGUSER	username of the database administrator
# PGGROUP	group of the database administrator
# PGHOME	home directory of the database administrator and location of
#		the databases
#
PGUSER?=		pgsql
PGGROUP?=		pgsql
PGHOME?=		${PREFIX}/${PGUSER}
FILES_SUBST+=		PGUSER=${PGUSER}
FILES_SUBST+=		PGHOME=${PGHOME}
BUILD_DEFS=		PGUSER PGROUP PGHOME

PKG_USERS=		${PGUSER}:${PGGROUP}::PostgreSQL\\ database\\ administrator:${PGHOME}:${SH}
PKG_GROUPS=		${PGGROUP}

RCD_SCRIPTS=		pgsql
OWN_DIRS_PERMS=		${PGHOME} ${PGUSER} ${PGGROUP} 0755

post-buildlink:
#
# Avoid conflict between "${LOCALBASE}/include/openssl/des.h" and
# "/usr/include/crypt.h" -- we want the definitions in the former.
#
.if (${OPSYS} == "SunOS")
	${TOUCH} ${BUILDLINK_DIR}/include/crypt.h
.endif

pre-install:
	@case "X${PGUSER}" in						\
	Xbin|Xetc|Xinclude|Xinfo|Xlib|Xlibdata|Xlibexec|Xman|Xsbin|Xshare) \
		${ECHO} "You have chosen PGUSER=${PGUSER} which will";	\
		${ECHO} "cause trouble, because the postgres home directory"; \
		${ECHO} "would be ${PGHOME}.  Please";			\
		${ECHO} "set PGUSER to something more reasonable";	\
		${ECHO} "like pgsql.";					\
		${ECHO} "";						\
		${FALSE};						\
		;;							\
	esac

post-install:
	${GTAR} zxCf ${PREFIX}/man ${WRKSRC}/doc/man.tar.gz		\
		`${SED} -e "s|^#.*||" ${FILESDIR}/man.server`

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
