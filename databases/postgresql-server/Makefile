# $NetBSD: Makefile,v 1.39 2004/04/27 05:44:22 snj Exp $

PKGNAME=		postgresql-server-${BASE_VERS}
PKGREVISION=		4
SVR4_PKGNAME=		pstgs
COMMENT=		PostgreSQL database server programs

DEPENDS+=		postgresql-client>=${BASE_VERS}:../../databases/postgresql-client

# mips has no TAS implementation
NOT_FOR_PLATFORM=	*-*-mips

USE_BUILDLINK3=		yes

.include "../../databases/postgresql/Makefile.common"

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
BUILD_DIRS=		${WRKSRC}/src/backend
BUILD_DIRS+=		${WRKSRC}/src/backend/utils/mb/conversion_procs

.if defined(USE_PAM)
.  include "../../security/PAM/buildlink3.mk"
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
FILES_SUBST+=		PGGROUP=${PGGROUP}
FILES_SUBST+=		PGHOME=${PGHOME}
BUILD_DEFS=		PGUSER PGGROUP PGHOME

PKG_USERS=		${PGUSER}:${PGGROUP}::PostgreSQL\\ database\\ administrator:${PGHOME}:${SH}
PKG_GROUPS=		${PGGROUP}

RCD_SCRIPTS=		pgsql

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

.include "../../databases/postgresql-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
