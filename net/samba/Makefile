# $NetBSD: Makefile,v 1.163 2006/09/14 16:17:43 rillig Exp $

.include "Makefile.mirrors"

DISTNAME=		samba-3.0.22
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		${SAMBA_MIRRORS:=old-versions/}
DIST_SUBDIR=		${DISTNAME}

.include "Makefile.patches"

MAINTAINER=		jlam@pkgsrc.org
HOMEPAGE=		http://www.samba.org/
COMMENT=		SMB/CIFS protocol server suite

CONFLICTS+=		ja-samba-[0-9]* pam-smbpass-[0-9]* tdb-[0-9]*	\
			winbind-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME}/source
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	samba
PKG_SYSCONFVAR=		samba

SAMBA_ETCDIR?=		${PKG_SYSCONFDIR}
SAMBA_LIBDIR?=		${PREFIX}/lib/samba
SAMBA_LOCKDIR?=		${SAMBA_VARDIR}/run/samba
SAMBA_LOGDIR?=		${SAMBA_VARDIR}/log
SAMBA_PIDDIR?=		${SAMBA_VARDIR}/run
SAMBA_PRIVATE?=		${SAMBA_ETCDIR}/private
SAMBA_STATEDIR?=	${SAMBA_VARDIR}/db/samba
SAMBA_VARDIR?=		${VARBASE}
WINBINDD_RCD_SCRIPT=	# empty

FILES_SUBST+=		SAMBA_ETCDIR=${SAMBA_ETCDIR:Q}
FILES_SUBST+=		SAMBA_LOCKDIR=${SAMBA_LOCKDIR:Q}
FILES_SUBST+=		SAMBA_LOGDIR=${SAMBA_LOGDIR:Q}
FILES_SUBST+=		SAMBA_PIDDIR=${SAMBA_PIDDIR:Q}
FILES_SUBST+=		SAMBA_PRIVATE=${SAMBA_PRIVATE:Q}
FILES_SUBST+=		SAMBA_STATEDIR=${SAMBA_STATEDIR:Q}
FILES_SUBST+=		SAMBA_VARDIR=${SAMBA_VARDIR:Q}
FILES_SUBST+=		WINBINDD_RCD_SCRIPT=${WINBINDD_RCD_SCRIPT:Q}

CONFIGURE_ARGS+=	--with-configdir=${SAMBA_ETCDIR:Q}
CONFIGURE_ARGS+=	--with-libdir=${SAMBA_LIBDIR:Q}
CONFIGURE_ARGS+=	--with-lockdir=${SAMBA_LOCKDIR:Q}
CONFIGURE_ARGS+=	--with-logfilebase=${SAMBA_LOGDIR:Q}
CONFIGURE_ARGS+=	--with-piddir=${SAMBA_PIDDIR:Q}
CONFIGURE_ARGS+=	--with-privatedir=${SAMBA_PRIVATE:Q}
CONFIGURE_ARGS+=	--with-statedir=${SAMBA_STATEDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${SAMBA_VARDIR:Q}

CONFIGURE_ARGS+=	--with-swatdir=${PREFIX}/share/samba/swat
CONFIGURE_ARGS+=	--with-libsmbclient

.include "../../converters/libiconv/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libiconv=${BUILDLINK_PREFIX.iconv}

USE_GNU_READLINE=	yes
.include "../../devel/readline/buildlink3.mk"
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}

.include "options.mk"

# Only Linux supports smbmount for mounting a Samba share into the
# filesystem.
#
.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-smbmount
PLIST_SUBST+=		SMBMOUNT=
.else
PLIST_SUBST+=		SMBMOUNT="@comment "
.endif

# mktemp is useful for the replacement adduser script, but don't require
# a full dependency since it's not actually needed by samba.
#
USE_TOOLS+=		mktemp

.if !defined(PWD_MKDB)
PWD_MKDB!=	${TYPE} pwd_mkdb 2>&1 | \
		${AWK} '/not found/ { print "pwd_mkdb"; exit } { print $$3 }'
MAKEFLAGS+=	PWD_MKDB=${PWD_MKDB:Q}
.endif
FILES_SUBST+=	MKTEMP=${MKTEMP:Q}
FILES_SUBST+=	PWD_MKDB=${PWD_MKDB:Q}

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

CONF_FILES=		${EGDIR}/smb.conf.default ${SAMBA_ETCDIR}/smb.conf
MAKE_DIRS=		${SAMBA_VARDIR} ${SAMBA_LOGDIR} ${SAMBA_PIDDIR}
OWN_DIRS=		${SAMBA_ETCDIR} ${SAMBA_LOCKDIR} ${SAMBA_STATEDIR}
OWN_DIRS_PERMS=		${SAMBA_PRIVATE} ${ROOT_USER} ${ROOT_GROUP} 0700
RCD_SCRIPTS+=		samba nmbd smbd ${WINBINDD_RCD_SCRIPT}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/adduser.sh ${WRKDIR}/deluser.sh
SUBST_SED.paths+=	-e 's,@AWK@,${AWK},g' -e 's,@CAT@,${CAT},g'
SUBST_SED.paths+=	-e 's,@MKTEMP@,${MKTEMP},g' -e 's,@RM@,${RM},g'
SUBST_SED.paths+=	-e 's,@PWD_MKDB@,${PWD_MKDB},g' -e 's,@SH@,${SH},g'
SUBST_STAGE.paths=	post-patch

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-configure
SUBST_FILES.mandir=	Makefile.in
SUBST_SED.mandir=	-e 's,@mandir@,${PREFIX}/${PKGMANDIR},g'

# Get the shared library major and minors for the installed shared
# libraries.  We'll need these to create the versioned symlinks for
# the shared libraries because samba Makefile doesn't do it on its
# own.
#
.for LIB in LIBSMBCLIENT LIBMSRPC
.  for NUM in MAJOR MINOR
${LIB}_${NUM}_cmd=	${AWK} -F= '/^${LIB}_${NUM}/ { print $$2; }'	\
				${WRKSRC}/Makefile.in
${LIB}_${NUM}=		${${LIB}_${NUM}_cmd:sh}
PLIST_SUBST+=		${LIB}_${NUM}=${${LIB}_${NUM}}
.  endfor
.endfor

.PHONY: install-samba-lib-symlinks
install-samba-lib-symlinks:
	cd ${SAMBA_LIBDIR} && ${LN} -s libmsrpc.so			\
		libmsrpc.so.${LIBMSRPC_MAJOR}
	cd ${SAMBA_LIBDIR} && ${LN} -s libmsrpc.so			\
		libmsrpc.so.${LIBMSRPC_MAJOR}.${LIBMSRPC_MINOR}
	cd ${SAMBA_LIBDIR} && ${LN} -s libsmbclient.so			\
		libsmbclient.so.${LIBSMBCLIENT_MAJOR}
	cd ${SAMBA_LIBDIR} && ${LN} -s libsmbclient.so			\
		libsmbclient.so.${LIBSMBCLIENT_MAJOR}.${LIBSMBCLIENT_MINOR}

post-extract:
	${CP} ${FILESDIR}/adduser.sh ${FILESDIR}/deluser.sh ${WRKDIR}

post-install: install-samba-lib-symlinks
	${RMDIR} ${PREFIX}/share/samba/swat/lang/ja/include
	${RMDIR} ${PREFIX}/share/samba/swat/lang/ja/images
	${RMDIR} ${PREFIX}/share/samba/swat/lang/tr/include
	for d in idmap pdb rpc; do					\
		${RMDIR} ${SAMBA_LIBDIR}/$$d;				\
	done
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/../docs/registry; for f in *.reg; do		\
		${INSTALL_DATA} $${f} ${DOCDIR}/$${f};			\
	done
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/adduser.sh ${EGDIR}/adduser.sh
	${INSTALL_SCRIPT} ${WRKDIR}/deluser.sh ${EGDIR}/deluser.sh
	cd ${WRKSRC}/../examples; ${INSTALL_DATA} LDAP/samba.schema ${EGDIR}
	cd ${WRKSRC}/../examples; ${INSTALL_DATA} smb.conf.default ${EGDIR}
	cd ${WRKSRC}/script; ${INSTALL_SCRIPT} mknissmbpasswd.sh ${EGDIR}
	cd ${WRKSRC}/script; ${INSTALL_SCRIPT} mknissmbpwdtbl.sh ${EGDIR}
	cd ${WRKSRC}/script; ${INSTALL_SCRIPT} mksmbpasswd.sh ${EGDIR}
	cd ${WRKSRC}/script; ${INSTALL_SCRIPT} updatesmbpasswd.sh ${EGDIR}

.include "../../mk/bsd.pkg.mk"
