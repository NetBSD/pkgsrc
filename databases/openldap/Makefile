# $NetBSD: Makefile,v 1.100 2005/08/03 21:01:40 jlam Exp $

DISTNAME=	openldap-2.2.27
PKGREVISION=	1
SVR4_PKGNAME=	oldap
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.openldap.org/pub/OpenLDAP/openldap-release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.OpenLDAP.org/
COMMENT=	Lightweight directory access protocol server and client package

CONFLICTS+=		ldapsdk-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		test

MAKE_ENV+=		LIBMODE=${LIBMODE}
OPENLDAP_ETCDIR=	${PKG_SYSCONFDIR}/openldap
OPENLDAP_MODULEDIR=	${PREFIX}/lib/openldap
OPENLDAP_VARDIR=	${VARBASE}/openldap
FILES_SUBST+=		OPENLDAP_ETCDIR=${OPENLDAP_ETCDIR:Q}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

CPPFLAGS.Darwin+=	-DBIND_8_COMPAT

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${OPENLDAP_VARDIR:Q}
CONFIGURE_ARGS+=	--enable-dynamic   # link servers against shared libs
CONFIGURE_ARGS+=	--with-tls=openssl

# SLAPD options
CONFIGURE_ARGS+=	--enable-crypt
.if !empty(PKG_OPTIONS:Msasl)
CONFIGURE_ARGS+=	--enable-spasswd
.endif
CONFIGURE_ARGS+=	--enable-wrappers

SLAPD_BACKEND_MODULES=	dnssrv ldap ldbm meta \
			monitor:static null passwd shell
.for _mod_ in ${SLAPD_BACKEND_MODULES}
.  if !empty(PKG_OPTIONS:Mdynamic)
CONFIGURE_ARGS+=	--enable-${_mod_:C/\:.*//}${_mod_:N*\:static:C/.*/=mod/}
.  else
CONFIGURE_ARGS+=	--enable-${_mod_:C/\:.*//}
.  endif
.endfor
.undef _mod_

OPENLDAP_FILEPERMS=	${ROOT_USER} ${ROOT_GROUP} 0600
OPENLDAP_DIRPERMS=	${ROOT_USER} ${ROOT_GROUP} 0700

USE_PKGINSTALL=		yes
EGDIR=			${PREFIX}/share/examples/openldap
MAKE_DIRS=		${OPENLDAP_ETCDIR} ${OPENLDAP_ETCDIR}/schema
OWN_DIRS=		${OPENLDAP_VARDIR} ${OPENLDAP_VARDIR}/run
OWN_DIRS_PERMS=		${OPENLDAP_VARDIR}/openldap-data ${OPENLDAP_DIRPERMS}
OWN_DIRS_PERMS+=	${OPENLDAP_VARDIR}/openldap-ldbm ${OPENLDAP_DIRPERMS}
OWN_DIRS_PERMS+=	${OPENLDAP_VARDIR}/openldap-slurp ${OPENLDAP_DIRPERMS}

CNFS=			ldap.conf ${CNFS_SCHEMAS_cmd:sh}
CNFS_SCHEMAS_cmd=	${SED} -ne "/\.schema$$/{ s,share/examples/openldap/,,; p; }" ${PKGDIR}/PLIST
CNFS_PERMS=		slapd.conf

CONF_FILES=		# empty
CONF_FILES_PERMS=	# empty
.for FILE in ${CNFS}
CONF_FILES+=		${EGDIR}/${FILE} ${OPENLDAP_ETCDIR}/${FILE}
.endfor
.for FILE in ${CNFS_PERMS}
CONF_FILES_PERMS+=	${EGDIR}/${FILE} ${OPENLDAP_ETCDIR}/${FILE}	\
			${OPENLDAP_FILEPERMS}
.endfor
RCD_SCRIPTS=		slapd

PTHREAD_OPTS+=		require

.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.if ${PTHREAD_TYPE} == "native"
CONFIGURE_ARGS+=	--with-threads
.elif ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-threads=pth
.endif
RCD_SCRIPTS+=		slurpd

MAKE_FLAGS+=		moduledir=${OPENLDAP_MODULEDIR:Q}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

# Set the correct file modes for the example config files.
post-install:
.for _file_ in ${CNFS} ${CNFS_PERMS}
	${CHMOD} ${SHAREMODE} ${EGDIR}/${_file_}
	${RM} ${EGDIR}/${_file_}.default
.endfor

.include "../../mk/bsd.pkg.mk"
