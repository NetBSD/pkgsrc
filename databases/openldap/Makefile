# $NetBSD: Makefile,v 1.83 2004/10/03 00:13:21 tv Exp $

DISTNAME=		openldap-2.2.13
SVR4_PKGNAME=		oldap
PKGREVISION=		2
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.openldap.org/pub/OpenLDAP/openldap-release/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://www.OpenLDAP.org/
COMMENT=		Lightweight directory access protocol server and client package

CONFLICTS+=		ldapsdk-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
TEST_TARGET=		test

OPENLDAP_ETCDIR=	${PKG_SYSCONFDIR}/openldap
OPENLDAP_MODULEDIR=	${PREFIX}/lib/openldap
OPENLDAP_VARDIR=	${VARBASE}/openldap
FILES_SUBST+=		OPENLDAP_ETCDIR=${OPENLDAP_ETCDIR}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

CPPFLAGS.Darwin+=	-DBIND_8_COMPAT

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${OPENLDAP_VARDIR}
CONFIGURE_ARGS+=	--enable-dynamic   # link servers against shared libs
CONFIGURE_ARGS+=	--with-tls=openssl

# SLAPD options
CONFIGURE_ARGS+=	--enable-crypt
.if !empty(PKG_OPTIONS:Msasl)
CONFIGURE_ARGS+=	--enable-spasswd
.endif
CONFIGURE_ARGS+=	--enable-wrappers

SLAPD_BACKEND_MODULES=	bdb:static dnnsrv hdb ldap ldbm meta		\
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
OWN_DIRS_PERMS=		${OPENLDAP_VARDIR}/openldap-ldbm ${OPENLDAP_DIRPERMS}
OWN_DIRS_PERMS+=	${OPENLDAP_VARDIR}/openldap-slurp ${OPENLDAP_DIRPERMS}

CNFS=			ldap.conf					\
			schema/corba.schema schema/core.schema		\
			schema/java.schema schema/inetorgperson.schema	\
			schema/cosine.schema schema/misc.schema		\
			schema/nis.schema schema/openldap.schema
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

# On some platforms, while the package does build correctly using GNU pth,
# slapd isn't able to pass "make test".  One those platforms, don't build
# openldap with threads support unless we're using the native thread
# library.
#
OPENLDAP_PTH_BROKEN_PLATFORMS?=	# empty
.for _pattern_ in ${OPENLDAP_PTH_BROKEN_PLATFORMS}
.  if !empty(MACHINE_PLATFORM:M${_pattern_})
OPENLDAP_PTHREAD_OPTS?=	native
.  endif
.endfor
OPENLDAP_PTHREAD_OPTS?=	require
PTHREAD_OPTS+=		${OPENLDAP_PTHREAD_OPTS}

.include "../../databases/db4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.if ${PTHREAD_TYPE} == "native"
CONFIGURE_ARGS+=	--with-threads
PLIST_SUBST+=		SLURPD_COMMENT=
RCD_SCRIPTS+=		slurpd
.elif ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-threads=pth
PLIST_SUBST+=		SLURPD_COMMENT=
RCD_SCRIPTS+=		slurpd
.else
CONFIGURE_ARGS+=	--without-threads
PLIST_SUBST+=		SLURPD_COMMENT="@comment "
.endif

MAKE_FLAGS+=		moduledir=${OPENLDAP_MODULEDIR}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

.include "../../mk/bsd.pkg.mk"
