# $NetBSD: Makefile,v 1.21 1999/01/03 13:13:12 frueauf Exp $
# FreeBSD Id: Makefile,v 1.22 1997/12/24 01:21:37 alex Exp

DISTNAME=	postgresql-6.3.2
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.PostgreSQL.org/pub/ \
		ftp://ftp.jaist.ac.jp/pub/dbms/postgres95/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.PostgreSQL.ORG/

DEPENDS+=	tk-8.0p2:../../x11/tk80
DEPENDS+=	tcl-8.0p2:../../lang/tcl80
DEPENDS+=	addnerd-1.6:../../sysutils/addnerd
DEPENDS+=	bison-1.25:../../devel/bison

NOT_FOR_ARCHS=	alpha	# Needs ELF clue
NOT_FOR_ARCHS+=	m68k

NO_PACKAGE=	"Requires pgsql uid"

WRKSRC=		${WRKDIR}/${DISTNAME}/src
PLIST_SRC=	${WRKDIR}/PLIST.tmp

PGUSER?=	pgsql
PGGROUP?=	ingres

USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
HAS_CONFIGURE=	yes
CONFIGURE_ARGS= --prefix=${PREFIX}/${PGUSER} \
		--enable-locale \
		--with-tcl \
		--with-includes=${PREFIX}/include \
		--with-libs=${PREFIX}/lib \
		--with-template=`${ECHO} ${OPSYS} | ${TR} '[A-Z]' '[a-z]'`

.include "../../mk/bsd.prefs.mk"

pre-extract:
	@(case "X${PGUSER}" in						\
	Xbin|Xetc|Xinclude|Xinfo|Xlib|Xlibdata|Xlibexec|Xman|Xsbin|Xshare)\
		gooduser=no;						\
		;;							\
	*)								\
		gooduser=yes;						\
		;;							\
	esac;								\
	if [ $$gooduser = "no" ]; then					\
		${ECHO} "You have choosen PGUSER=${PGUSER} which will";	\
		${ECHO} "cause trouble, because postgres would get";	\
		${ECHO} "installed to ${PREFIX}/${PGUSER}. So please";	\
		${ECHO} "set PGUSER to something more reasonable";	\
		${ECHO} "like pgsql.";					\
		${ECHO} "";						\
		${FALSE};						\
	fi)

post-build:
	@ ${ECHO} "------------------------------------------------------------"
	@ ${ECHO} "Dump existing databases, before installing new db version !!"
	@ ${ECHO} "Detailed instructions, see INSTALL file under ${WRKDIR}...  "
	@ ${ECHO} "------------------------------------------------------------"

pre-install:
.if defined(PACKAGE_BUILDING)
	${RM} -rf ${PREFIX}/${PGUSER}
.endif
	@${MKDIR} ${PREFIX}/${PGUSER}
	@${SETENV} ${MAKE_ENV} addnerd -h ${PREFIX} -g ${PGGROUP} ${PGUSER}
	@${SED} -e 's|@PGUSER@|${PGUSER}|g' ${PKGDIR}/PLIST > ${PLIST_SRC}

post-install:
	@ if [ ! -f ${PREFIX}/${PGUSER}/.profile ]; then \
		${ECHO} "PATH=\$${PATH}:${PREFIX}/${PGUSER}/bin" \
			> ${PREFIX}/${PGUSER}/.profile; \
		${ECHO} "MANPATH=\$${MANPATH}:${PREFIX}/${PGUSER}/man" \
			>> ${PREFIX}/${PGUSER}/.profile; \
		${ECHO} "PGLIB=${PREFIX}/${PGUSER}/lib" \
			>> ${PREFIX}/${PGUSER}/.profile; \
		${ECHO} "# note: PGDATA overwrites the -D startup option" \
			>> ${PREFIX}/${PGUSER}/.profile; \
		${ECHO} "PGDATA=${PREFIX}/${PGUSER}/data" \
			>> ${PREFIX}/${PGUSER}/.profile; \
		${ECHO} "DISPLAY=:0" \
			>> ${PREFIX}/${PGUSER}/.profile; \
		${ECHO} "export PATH MANPATH PGLIB PGDATA DISPLAY" \
			>> ${PREFIX}/${PGUSER}/.profile; \
		${ECHO} "# if you want to make regression tests use this TZ" \
			>> ${PREFIX}/${PGUSER}/.profile; \
		${ECHO} "#TZ=PST8PDT" \
			>> ${PREFIX}/${PGUSER}/.profile; \
		${ECHO} "#export TZ" \
			>> ${PREFIX}/${PGUSER}/.profile; \
	fi
	@/usr/sbin/chown -R ${PGUSER}:${PGGROUP} ${PREFIX}/${PGUSER}
	@${ECHO} 'Initializing PostgreSQL Databases - this may take a few minutes...'
	@case `${GREP} -c '^${PREFIX}/${PGUSER}/lib$$' /etc/ld.so.conf` in	\
	0)									\
		${ECHO} "************** WARNING ********************";		\
		${ECHO} "Please add ${PREFIX}/${PGUSER}/lib to /etc/ld.so.conf";\
		${ECHO} "so that this package is usable after any reboot";	\
		${ECHO} "************** WARNING ********************";		\
		;;								\
	esac
	@${ECHO} '${SETENV} PATH=${PREFIX}/${PGUSER}/bin:$$PATH ${PREFIX}/${PGUSER}/bin/initdb --pglib=${PREFIX}/${PGUSER}/lib --pgdata=${PREFIX}/${PGUSER}/data' | su -l ${PGUSER}
	@${SED} -e "s=!!PREFIX!!=${PREFIX}=g" < ${FILESDIR}/pgsql.sh.tmpl \
		> ${PREFIX}/etc/rc.d/pgsql.sh
	@/bin/chmod 554 ${PREFIX}/etc/rc.d/pgsql.sh
	@/usr/sbin/chown root.${PGGROUP} ${PREFIX}/etc/rc.d/pgsql.sh
	@${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PREFIX}/${PGUSER}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/pgsql
	${CP} -R ${WRKDIR}/${DISTNAME}/doc/* ${PREFIX}/share/doc/pgsql
.endif
.if !defined(BATCH)
	@${CAT} ${FILESDIR}/post-install-notes
.endif

.include "../../mk/bsd.pkg.mk"
