# $NetBSD: Makefile,v 1.47 2000/03/18 17:43:16 jlam Exp $
# FreeBSD Id: Makefile,v 1.22 1997/12/24 01:21:37 alex Exp
#

BUILD_DEPENDS+=		${LOCALBASE}/bin/bison:../../devel/bison
DEPENDS+=		ncurses>=4.2:../../devel/ncurses
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

CPPFLAGS+=		-I${LOCALBASE}/include	# ncurses.h, readline.h

INSTALL_TARGET=		install install-man

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
	cd ${PREFIX}; ${MV} include/libpq++.H include/libpq++.h
	cd ${PREFIX}/include; ${RMDIR} -p port/netbsd

.for PROG in ecpg pg_dump pg_id pg_passwd pg_version postgres psql
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

	cd ${WRKDIR}/${DISTNAME}/doc; \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} all
	cd ${WRKDIR}/${DISTNAME}/doc; ${INSTALL_DATA} \
		FAQ FAQ_DEV README.fsync TODO bug.template internals.ps \
		admin.ps.gz programmer.ps.gz tutorial.ps.gz user.ps.gz \
		${PREFIX}/share/doc/postgresql
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/postgresql

	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../databases/postgresql/Makefile.common"
