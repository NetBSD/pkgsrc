# $NetBSD: Makefile,v 1.13 1998/06/22 11:19:41 agc Exp $
# FreeBSD Id: Makefile,v 1.22 1997/12/24 01:21:37 alex Exp

DISTNAME=	postgresql-6.3.2
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.PostgreSQL.org/pub/ \
		ftp://ftp.jaist.ac.jp/pub/dbms/postgres95/

MAINTAINER=	packages@netbsd.org

DEPENDS+=	tk-8.0p2:../../x11/tk80
DEPENDS+=	tcl-8.0p2:../../lang/tcl80
DEPENDS+=	addnerd-1.5:../../sysutils/addnerd

NO_PACKAGE=	"Requires pgsql uid"
WRKSRC=		${WRKDIR}/${DISTNAME}/src

PGUSER?=	pgsql
PGGROUP?=	ingres

USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
HAS_CONFIGURE=	yes
CONFIGURE_ARGS= --prefix=${PREFIX}/pgsql \
		--enable-locale \
		--with-tcl \
		--with-includes=${PREFIX}/include \
		--with-libs=${PREFIX}/lib \
		--with-template=`uname -s | ${TR} '[A-Z]' '[a-z]'`

.include "../../mk/bsd.prefs.mk"

post-build:
	@ ${ECHO} "------------------------------------------------------------"
	@ ${ECHO} "Dump existing databases, before installing new db version !!"
	@ ${ECHO} "Detailed instructions, see INSTALL file under ${WRKDIR}...  "
	@ ${ECHO} "------------------------------------------------------------"

pre-install:
.if defined(PACKAGE_BUILDING)
	${RM} -rf ${PREFIX}/pgsql
.endif
	@${MKDIR} ${PREFIX}/pgsql
	@${SETENV} ${MAKE_ENV} addnerd -g ${PGGROUP} ${PGUSER}

post-install:
	@ if [ ! -f ${PREFIX}/pgsql/.profile ]; then \
		${ECHO} "PATH=\$${PATH}:${PREFIX}/pgsql/bin" \
			> ${PREFIX}/pgsql/.profile; \
		${ECHO} "MANPATH=\$${MANPATH}:${PREFIX}/pgsql/bin" \
			>> ${PREFIX}/pgsql/.profile; \
		${ECHO} "PGLIB=${PREFIX}/pgsql/lib" \
			>> ${PREFIX}/pgsql/.profile; \
		${ECHO} "# note: PGDATA overwrites the -D startup option" \
			>> ${PREFIX}/pgsql/.profile; \
		${ECHO} "PGDATA=${PREFIX}/pgsql/data" \
			>> ${PREFIX}/pgsql/.profile; \
		${ECHO} "DISPLAY=:0" \
			>> ${PREFIX}/pgsql/.profile; \
		${ECHO} "export PATH MANPATH PGLIB PGDATA DISPLAY" \
			>> ${PREFIX}/pgsql/.profile; \
		${ECHO} "# if you want to make regression tests use this TZ" \
			>> ${PREFIX}/pgsql/.profile; \
		${ECHO} "#TZ=PST8PDT" \
			>> ${PREFIX}/pgsql/.profile; \
		${ECHO} "#export TZ" \
			>> ${PREFIX}/pgsql/.profile; \
	fi
	@/usr/sbin/chown -R ${PGUSER}:${PGGROUP} ${PREFIX}/pgsql
	@${ECHO} 'Initializing PostgreSQL Databases - this may take a few minutes...'
	@${LDCONFIG} -m ${PREFIX}/pgsql/lib || ${TRUE}
	@${ECHO} '${SETENV} PATH=${PREFIX}/pgsql/bin:$$PATH ${PREFIX}/pgsql/bin/initdb --pglib=${PREFIX}/pgsql/lib --pgdata=${PREFIX}/pgsql/data' | su -l ${PGUSER}
	@${SED} -e "s=!!PREFIX!!=${PREFIX}=g" < ${FILESDIR}/pgsql.sh.tmpl \
		> ${PREFIX}/etc/rc.d/pgsql.sh
	@/bin/chmod 554 ${PREFIX}/etc/rc.d/pgsql.sh
	@/usr/sbin/chown root.${PGGROUP} ${PREFIX}/etc/rc.d/pgsql.sh
	@${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PREFIX}/pgsql
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/pgsql
	${CP} -R ${WRKDIR}/${DISTNAME}/doc/* ${PREFIX}/share/doc/pgsql
.endif
.if !defined(BATCH)
	@${CAT} ${FILESDIR}/post-install-notes
.endif

.include "../../mk/bsd.pkg.mk"
