# $NetBSD: Makefile,v 1.60 2001/02/13 02:37:43 jlam Exp $
# FreeBSD Id: Makefile,v 1.22 1997/12/24 01:21:37 alex Exp
#

.include "../../databases/postgresql/Makefile.common"

# NetBSD libedit's readline emulation doesn't support enough features, yet.
DEPENDS+=		readline-*:../../devel/readline

MAKEFILE=		GNUmakefile

# Needs ELF clue, mips has no TAS implementation
NOT_FOR_PLATFORM=	*-*-mips

.include "../../mk/bsd.prefs.mk"

# PGUSER	username of the database administrator
# PGGROUP	group of the database administrator
#
PGUSER?=		pgsql
PGGROUP?=		ingres

MESSAGE=		${FILESDIR}/post-install-notes
DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL
PGHOME=			${PREFIX}/${PGUSER}

BUILD_DEFS=		PGUSER PGROUP
PLIST_SUBST=		PGUSER=${PGUSER}
PLIST_SRC+=		${PKGDIR}/PLIST
PLIST_SRC+=		${PKGDIR}/PLIST.spi
PLIST_SRC+=		${PKGDIR}/PLIST.dirrm

CONFIGURE_ARGS+=	--without-perl --without-odbc --without-tcl
CONFIGURE_ARGS+=	--with-includes="${LOCALBASE}/include"
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

.if ${OPSYS} == "NetBSD"
.if exists(/usr/sbin/user)
ADDUSER=		/usr/sbin/useradd
ADDGROUP=		/usr/sbin/groupadd
.else
DEPENDS+=		user>=20000313:../../sysutils/user
ADDUSER=		${LOCALBASE}/sbin/useradd
ADDGROUP=		${LOCALBASE}/sbin/groupadd
.endif
.elif ${OPSYS} == "SunOS"
ADDUSER=		useradd
ADDGROUP=		groupadd
.endif

# The following alpha-specific patch fixes problems in the 7.0.x release
# that will be fixed in a more complete way in the forthcoming 7.1 release.
#
.if ${MACHINE_ARCH} == "alpha"
post-patch:
	cd ${WRKSRC} && ${PATCH} < ${FILESDIR}/postgresql-7.0.3-alpha.diff
.endif

post-build:
	${SED}	-e 's|@PATH@|${PATH}|g' \
		-e 's|@MANPATH@|${MANPATH}|g' \
		-e 's|@PREFIX@|${PREFIX}|g' \
		< ${FILESDIR}/profile.pgsql > ${WRKDIR}/profile.pgsql
	${SED}	-e "s|@PREFIX@|${PREFIX}|g" \
		-e "s|@PGUSER@|${PGUSER}|g" \
		-e "s|@SU@|${SU}|g" \
		< ${FILESDIR}/pgsql.sh > ${WRKDIR}/pgsql.sh

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

	${SED}	-e 's|@PGUSER@|${PGUSER}|g' \
		-e "s,@PGGROUP@,${PGGROUP},g" \
		-e "s,@CAT@,${CAT},g" \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s,@PGUSER@,${PGUSER},g" \
		-e "s,@PGGROUP@,${PGGROUP},g" \
		-e "s,@ADDUSER@,${ADDUSER},g" \
		-e "s,@ADDGROUP@,${ADDGROUP},g" \
		-e "s,@CAT@,${CAT},g" \
		-e "s,@CHGRP@,${CHGRP},g" \
		-e "s,@CHMOD@,${CHMOD},g" \
		-e "s,@CHOWN@,${CHOWN},g" \
		-e "s,@CP@,${CP},g" \
		-e "s,@GREP@,${GREP},g" \
		-e "s,@MKDIR@,${MKDIR},g" \
		-e "s,@RM@,${RM},g" \
		-e "s,@SU@,${SU},g" \
		-e "s,@TOUCH@,${TOUCH},g" \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	cd ${PREFIX}/include/pgsql; ${RMDIR} -p port/netbsd

	dirlist=`${GREP} "^@dirrm" ${PKGDIR}/PLIST.spi \
	    | ${AWK} '{ print $$2 }'`; \
	for dir in $$dirlist; do \
		${INSTALL_DATA_DIR} ${PREFIX}/$$dir; \
	done
	filelist=`${GREP} "^include/pgsql/" ${PKGDIR}/PLIST.spi \
	    | ${SED} "s,^include/pgsql/,,g"`; \
	cd ${WRKSRC}/include; for file in $$filelist; do \
		${INSTALL_DATA} $$file ${PREFIX}/include/pgsql/$$file; \
	done

.for PROG in ecpg pg_dump pg_encoding pg_id pg_passwd pg_version postgres psql
	strip ${PREFIX}/bin/${PROG}
.endfor
	${INSTALL_DATA} ${WRKDIR}/profile.pgsql ${PGHOME}/.profile.pgsql
	${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PGHOME}
	${CHOWN} -R ${PGUSER}:${PGGROUP} ${PGHOME}

	${INSTALL_SCRIPT} ${WRKDIR}/pgsql.sh ${PREFIX}/etc/rc.d/pgsql

	${CAT} ${FILESDIR}/exclude ${FILESDIR}/man.tcl ${FILESDIR}/man.tk \
		| ${SED} "s,^#.*,," \
		| ${GTAR} zxCXf ${PREFIX}/man - \
			${WRKDIR}/${DISTNAME}/doc/man.tar.gz

	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/postgresql
	cd ${WRKDIR}/${DISTNAME}/doc; \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} all
	cd ${WRKDIR}/${DISTNAME}/doc; ${INSTALL_DATA} \
		FAQ FAQ_DEV README.Charsets README.fsync README.inet \
		README.locale README.mb README.mb.jp TODO \
		bug.template internals.ps \
		${PREFIX}/share/doc/postgresql
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/postgresql
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/html/postgresql

	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
