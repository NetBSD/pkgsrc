# $NetBSD: Makefile,v 1.50 2000/05/29 15:29:11 fredb Exp $
# FreeBSD Id: Makefile,v 1.22 1997/12/24 01:21:37 alex Exp
#

DEPENDS+=		readline-*:../../devel/readline

MAKEFILE=		GNUmakefile

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/sbin/user)
USERDIR=		/usr/sbin
.else
DEPENDS+=		user>=20000313:../../sysutils/user
USERDIR=		${LOCALBASE}/sbin
.endif

# Needs ELF clue, mips has no TAS implementation
NOT_FOR_PLATFORM=	*-*-alpha *-*-mips

# PGUSER	username of the database administrator
# PGGROUP	group of the database administrator
#
PGUSER?=		pgsql
PGGROUP?=		ingres

MESSAGE_FILE=		${FILESDIR}/post-install-notes
DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL
PGHOME=			${PREFIX}/${PGUSER}

BUILD_DEFS=		PGUSER PGROUP
PLIST_SUBST=		PGUSER=${PGUSER}

CONFIGURE_ARGS+=	--without-perl --without-odbc --without-tcl
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=		-I${LOCALBASE}/include	# readline.h

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

	${SED}	-e 's|@PGHOME@|${PGHOME}|g' \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e 's|@PGUSER@|${PGUSER}|g' \
		-e 's|@PGGROUP@|${PGGROUP}|g' \
		-e 's|@PGHOME@|${PGHOME}|g' \
		-e 's|@USERDIR@|${USERDIR}|g' \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	cd ${PREFIX}/include/pgsql; ${RMDIR} -p port/netbsd

.for PROG in ecpg pg_dump pg_encoding pg_id pg_passwd pg_version postgres psql
	strip ${PREFIX}/bin/${PROG}
.endfor
	${SED}	-e 's|@PATH@|${PATH}|g' \
		-e 's|@MANPATH@|${MANPATH}|g' \
		-e 's|@PREFIX@|${PREFIX}|g' \
		< ${FILESDIR}/profile.pgsql > ${WRKDIR}/profile.pgsql
	${INSTALL_DATA} ${WRKDIR}/profile.pgsql ${PGHOME}/.profile.pgsql
	${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PGHOME}
	${CHOWN} -R ${PGUSER}:${PGGROUP} ${PGHOME}

	${SED}	-e "s|@PREFIX@|${PREFIX}|g" \
		-e "s|@PGUSER@|${PGUSER}|g" \
		-e "s|@PGHOME@|${PGHOME}|g" \
		< ${FILESDIR}/pgsql.sh.tmpl > ${WRKDIR}/pgsql.sh
	${INSTALL} -c -o root -g ${PGGROUP} -m 554 \
		${WRKDIR}/pgsql.sh ${PREFIX}/etc/rc.d/pgsql.sh

	${CAT} ${FILESDIR}/exclude ${FILESDIR}/man.tcl ${FILESDIR}/man.tk \
		| ${SED} "s,^#.*,," \
		| ${GTAR} zxCXf ${PREFIX}/man - \
			${WRKDIR}/${DISTNAME}/doc/man.tar.gz

	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/postgresql
	cd ${WRKDIR}/${DISTNAME}/doc; \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} all
	cd ${WRKDIR}/${DISTNAME}/doc; ${INSTALL_DATA} \
		FAQ FAQ_DEV README.Charsets README.fsync README.inet \
		README.locale README.mb README.mb.jp TODO admin.ps.gz \
		bug.template internals.ps programmer.ps.gz tutorial.ps.gz \
		user.ps.gz \
		${PREFIX}/share/doc/postgresql
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/postgresql
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/html/postgresql

	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../databases/postgresql/Makefile.common"
