# $NetBSD: Makefile,v 1.37 1999/08/24 14:18:53 tron Exp $
# FreeBSD Id: Makefile,v 1.22 1997/12/24 01:21:37 alex Exp
#

DISTNAME=		postgresql-6.4.2
WRKSRC=			${WRKDIR}/${DISTNAME}/src
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.PostgreSQL.org/pub/ \
			ftp://ftp.sunsite.auc.dk/mirrors/www.postgresql.org/pub/ \
			ftp://ftp.jaist.ac.jp/pub/dbms/postgres95/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.PostgreSQL.ORG/

BUILD_DEPENDS+=		${LOCALBASE}/bin/bison:../../devel/bison
DEPENDS+=		tk-8.0.5:../../x11/tk80 \
			tcl-8.0.5:../../lang/tcl80 \
			addnerd-1.6:../../sysutils/addnerd

# Needs ELF clue, mips has no TAS implementation
NOT_FOR_PLATFORM=	*-*-alpha *-*-mips

PLIST_SRC=		${WRKDIR}/PLIST.tmp
REQ_FILE=		${WRKDIR}/REQ

PGUSER?=		pgsql
PGGROUP?=		ingres

USE_GMAKE=
MAKEFILE=		GNUmakefile
HAS_CONFIGURE=		yes
CONFIGURE_ARGS= 	--prefix=${PREFIX}/${PGUSER} \
			--enable-locale \
			--with-tcl \
			--with-tclconfig="${LOCALBASE}/lib/tcl8.0 ${LOCALBASE}/lib/tk8.0" \
			--with-includes="${LOCALBASE}/include ${LOCALBASE}/include/tcl8.0 ${LOCALBASE}/include/tk8.0" \
			--with-libs=${PREFIX}/lib \
			--with-template=`${ECHO} ${OPSYS} | ${TR} '[A-Z]' '[a-z]'`

INSTALL_TARGET=		install install-man

BUILD_DEFS+=		PGGROUP PGUSER

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
	${RM} -rf ${PREFIX}/${PGUSER}
	@${SED}  \
		-e 's|@PGUSER@|${PGUSER}|g' \
		-e 's|@PGGROUP@|${PGGROUP}|g' \
		-e 's|@PREFIX@|${PREFIX}|g' \
		-e 's|@LOCALBASE@|${LOCALBASE}|g' \
		<${PKGDIR}/REQ > ${REQ_FILE}
	@${SED}  \
		-e 's|@PGUSER@|${PGUSER}|g' \
		<${PKGDIR}/PLIST > ${PLIST_SRC}
	${SH} ${REQ_FILE} ${PKGNAME} INSTALL

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
	${LDCONFIG} ${PREFIX}/${PGUSER}/lib || ${TRUE}
	@${ECHO} '${SETENV} PATH=${PREFIX}/${PGUSER}/bin:$$PATH ${PREFIX}/${PGUSER}/bin/initdb --pglib=${PREFIX}/${PGUSER}/lib --pgdata=${PREFIX}/${PGUSER}/data' | su -l ${PGUSER}
	@${SED} -e "s=!!PREFIX!!=${PREFIX}=g" -e "s=!!PGUSER!!=${PGUSER}=g" \
		< ${FILESDIR}/pgsql.sh.tmpl > ${PREFIX}/etc/rc.d/pgsql.sh
	@/bin/chmod 554 ${PREFIX}/etc/rc.d/pgsql.sh
	@/usr/sbin/chown root:${PGGROUP} ${PREFIX}/etc/rc.d/pgsql.sh
	@${INSTALL} -c -o ${PGUSER} -g ${PGGROUP} -m 444 \
		${FILESDIR}/post-install-notes ${PREFIX}/${PGUSER}
	-${MKDIR} ${PREFIX}/share/doc/pgsql
	${CP} -R ${WRKDIR}/${DISTNAME}/doc/* ${PREFIX}/share/doc/pgsql
	${RM} -rf ${PREFIX}/share/doc/pgsql/src/CVS \
		${PREFIX}/share/doc/pgsql/src/graphics/CVS \
		${PREFIX}/share/doc/pgsql/src/sgml/ref/CVS \
		${PREFIX}/share/doc/pgsql/src/sgml/CVS \
		${PREFIX}/share/doc/pgsql/CVS
.if !defined(BATCH)
	@${CAT} ${FILESDIR}/post-install-notes
.endif
	@case `${GREP} -c '^${PREFIX}/${PGUSER}/lib$$' /etc/ld.so.conf` in	\
	0)									\
		${ECHO} "************** WARNING ********************";		\
		${ECHO} "Please add ${PREFIX}/${PGUSER}/lib to /etc/ld.so.conf";\
		${ECHO} "so that this package is usable after any reboot";	\
		${ECHO} "************** WARNING ********************";		\
		;;								\
	esac

.include "../../mk/bsd.pkg.mk"
