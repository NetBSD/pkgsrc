# $NetBSD: Makefile,v 1.44 1999/12/28 04:56:09 wiz Exp $
# FreeBSD Id: Makefile,v 1.22 1997/12/24 01:21:37 alex Exp
#

DISTNAME=		postgresql-6.5.3
WRKSRC=			${WRKDIR}/${DISTNAME}/src
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.PostgreSQL.org/pub/ \
			ftp://ftp.sunsite.auc.dk/mirrors/www.postgresql.org/pub/ \
			ftp://ftp.jaist.ac.jp/pub/dbms/postgres95/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.PostgreSQL.ORG/

DEPENDS+=		addnerd-1.6:../../sysutils/addnerd

BUILD_DEPENDS+=		${LOCALBASE}/bin/bison:../../devel/bison

# Evil stuff follows: I haven't figured out how to add flags to configure to
# nicely disable the ncurses and readline checks in the configure script, yet.
.if exists(${LOCALBASE}/include/ncurses.h)
DEPENDS+=		ncurses-4.2:../../devel/ncurses
.endif
.if exists(${LOCALBASE}/include/readline.h)
DEPENDS+=		readline-4.0:../../devel/readline
.endif

# Needs ELF clue, mips has no TAS implementation
NOT_FOR_PLATFORM=	*-*-alpha *-*-mips

MAKEFILE=		GNUmakefile
USE_GMAKE=		YES
USE_LIBTOOL=		YES

# Don't use GNU_CONFIGURE or else bsd.pkg.mk will override our custom PREFIX.
HAS_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

# If you don't want to use the Tcl/Tk frontend pgaccess, then you need to
# remove Tcl/Tk support by defining `PGSQL_USE_TCL=NO' in /etc/mk.conf
# or by typing: ${MAKE} PGSQL_USE_TCL=NO.
#

# Default to building with Tcl/Tk interface.
#
PGSQL_USE_TCL?=		YES

.if (${PGSQL_USE_TCL} == "YES")
DEPENDS+=		tcl-8.0.5:../../lang/tcl80
DEPENDS+=		tk-8.0.5:../../x11/tk80

TCLSH=			${LOCALBASE}/bin/tclsh8.0
TCL_INCDIR=		${LOCALBASE}/include/tcl8.0
TCL_CONFIGDIR=		${LOCALBASE}/lib/tcl8.0
TK_INCDIR=		${LOCALBASE}/include/tk8.0
TK_CONFIGDIR=		${LOCALBASE}/lib/tk8.0

USE_X11=		YES
CONFIGURE_ENV+=		TCLSH="${TCLSH}"
CONFIGURE_ARGS+=	--with-tcl \
			--with-tclconfig="${TCL_CONFIGDIR}" \
			--with-tkconfig="${TK_CONFIGDIR}" \
			--with-includes="${TCL_INCDIR} ${TK_INCDIR}" \
			--with-libraries="${LOCALBASE}/lib"
.endif

PGUSER?=		pgsql
PGGROUP?=		ingres
PGPREFIX=		${PREFIX}/${PGUSER}

BUILD_DEFS=		PGUSER PGROUP PGSQL_USE_TCL
MESSAGE_FILE=		${FILESDIR}/post-install-notes
REQ_FILE=		${WRKDIR}/REQ

PLIST_SRC=		${PKGDIR}/PLIST.notcl
.if (${PGSQL_USE_TCL} == "YES")
PLIST_SRC+=		${PKGDIR}/PLIST.tcl
.endif
PLIST_SRC+=		${PKGDIR}/PLIST.doc ${PKGDIR}/PLIST.dirrm
PLIST_SUBST=		PGUSER=${PGUSER}

CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM} \
			--prefix=${PGPREFIX} \
			--with-template="${LOWER_OPSYS}" \
			--enable-locale
LDFLAGS+=		-Wl,-R${PGPREFIX}/lib -L${PGPREFIX}/lib

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
		${ECHO} "installed to ${PGPREFIX}. So please";	\
		${ECHO} "set PGUSER to something more reasonable";	\
		${ECHO} "like pgsql.";					\
		${ECHO} "";						\
		${FALSE};						\
	fi)

post-extract:
	@${CP} ${FILESDIR}/Makefile.custom ${WRKSRC}

pre-build:
.if ${PGSQL_USE_TCL} == "YES"
	@${ECHO} "Building PostgreSQL with Tcl/Tk interface library."
.else
	@${ECHO} "To build without the \"PostgreSQL Tcl/Tk interface library\","
	@${ECHO} "libpgtcl, type: \"${MAKE} PGSQL_USE_TCL=NO\"."
.endif

post-build:
	@${ECHO} "------------------------------------------------------------"
	@${ECHO} "Dump existing databases, before installing new db version !!"
	@${ECHO} "Detailed instructions, see INSTALL file under ${WRKDIR}...  "
	@${ECHO} "------------------------------------------------------------"

pre-install:
	${RM} -rf ${PGPREFIX}
	${MKDIR} ${PGPREFIX}
	@${SED}	-e 's|@LOCALBASE@|${LOCALBASE}|g' \
		-e 's|@PGUSER@|${PGUSER}|g' \
		-e 's|@PGGROUP@|${PGGROUP}|g' \
		-e 's|@PREFIX@|${PREFIX}|g' \
		< ${PKGDIR}/REQ > ${REQ_FILE}
	${SH} ${REQ_FILE} ${PKGNAME} INSTALL

post-install:
	@${MV} ${PGPREFIX}/include/libpq++.H ${PGPREFIX}/include/libpq++.h
	@${TOUCH} ${PGPREFIX}/include/port/bsd/.keep_me

	@if [ ! -f ${PGPREFIX}/.profile ]; then \
		(${ECHO} "PATH=\$${PATH}:${PGPREFIX}/bin"; \
		 ${ECHO} "MANPATH=\$${MANPATH}:${PGPREFIX}/man"; \
		 ${ECHO} "PGLIB=${PGPREFIX}/lib"; \
		 ${ECHO} "# note: PGDATA overwrites the -D startup option"; \
		 ${ECHO} "PGDATA=${PGPREFIX}/data"; \
		 ${ECHO} "DISPLAY=:0"; \
		 ${ECHO} "export PATH MANPATH PGLIB PGDATA DISPLAY"; \
		 ${ECHO}; \
		 ${ECHO} "# if you want to make regression tests use this TZ"; \
		 ${ECHO} "#TZ=PST8PDT"; \
		 ${ECHO} "#export TZ"; \
		) > ${PGPREFIX}/.profile; \
	fi
	@${SED}	-e "s|@PGPREFIX@|${PGPREFIX}|g" \
		-e "s|@PGUSER@|${PGUSER}|g" \
		< ${FILESDIR}/pgsql.sh.tmpl > ${WRKDIR}/pgsql.sh
	@${INSTALL} -c -o root -g ${PGGROUP} -m 554 \
		${WRKDIR}/pgsql.sh ${PREFIX}/etc/rc.d/pgsql.sh
	@${INSTALL} -c -o ${PGUSER} -g ${PGGROUP} -m 444 \
		${FILESDIR}/post-install-notes ${PGPREFIX}

	@cd ${WRKDIR}/${DISTNAME}/doc; ${MAKE_PROGRAM} ${INSTALL_TARGET}
	@for file in \
	    FAQ FAQ_DEV README.fsync TODO bug.template internals.ps \
	    admin.ps.gz programmer.ps.gz tutorial.ps.gz user.ps.gz; do \
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/$${file} \
			${PREFIX}/share/doc/postgresql/$${file}; \
	done
	@${CHOWN} -R ${PGUSER}:${PGGROUP} ${PGPREFIX}

	@${ECHO} 'Initializing PostgreSQL Databases - this may take a few minutes...'
	@${ECHO} '${SETENV} PATH=${PGPREFIX}/bin:$$PATH ${PGPREFIX}/bin/initdb --pglib=${PGPREFIX}/lib --pgdata=${PGPREFIX}/data' | ${SU} -l ${PGUSER}

.include "../../mk/bsd.pkg.mk"
