# $NetBSD: Makefile,v 1.29 2004/10/03 00:17:53 tv Exp $

.include "Makefile.common"

PKGNAME=		ja-samba-${SAMBA_BASE_VERS}.${SAMBA_JA_VERS}
PKGREVISION=	1
CATEGORIES=		net

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://www.jp.samba.org/project/samba-ja/index.html.en
COMMENT=		Samba supporting I18N swat and L10N for Japanese

CONFLICTS+=		samba-[0-9]*

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

USE_PKGLOCALEDIR=	YES

USE_GNU_READLINE=	# uses rl_event_hook interface to GNU readline
CONFIGURE_ARGS+=	--with-readline

CONFIGURE_ARGS+=	--with-ssl
CONFIGURE_ARGS+=	--with-sslinc=${SSLBASE}
CFLAGS+=		-I${SSLBASE}/include/openssl	# ssl.h, err.h

# Force the use of the included gettext library this doesn't seem to link
# with the gettext-lib package.
#
CONFIGURE_ARGS+=	--with-included-gettext

.if defined(USE_CUPS) && (${USE_CUPS} == "YES")
.  include "../../print/cups/buildlink3.mk"
BUILD_DEFS+=		USE_CUPS
CONFIGURE_ARGS+=	--enable-cups
.endif

.if defined(USE_PAM)
.  include "../../security/PAM/buildlink3.mk"
BUILD_DEFS+=		USE_PAM
CONFIGURE_ARGS+=	--with-pam
.endif

.if defined(USE_OPENLDAP) && ${USE_OPENLDAP} == "YES"
.  include "../../databases/openldap/buildlink3.mk"
BUILD_DEFS+=		USE_OPENLDAP
CONFIGURE_ARGS+=	--with-ldapsam
PLIST_SUBST+=		SAMBA_LDAP=""
.else
PLIST_SUBST+=		SAMBA_LDAP="@comment "
MESSAGE_SRC=		${.CURDIR}/MESSAGE.common ${.CURDIR}/MESSAGE.smbpasswd
SMBPASSWD_FILE=		/dev/null ${SAMBA_PRIVATE}/smbpasswd		\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endif

# Microsoft DFS support
CONFIGURE_ARGS+=	--with-msdfs

MESSAGE_SUBST+=		SAMBA_PRIVATE=${SAMBA_PRIVATE}
MESSAGE_SUBST+=		ROOT_GROUP=${ROOT_GROUP}
MESSAGE_SUBST+=		ROOT_USER=${ROOT_USER}

DOCDIR=			${PREFIX}/share/doc/samba
EXAMPLESDIR=		${PREFIX}/share/examples/samba

CONF_FILES=		${EXAMPLESDIR}/smb.conf.default ${SAMBA_ETCDIR}/smb.conf
SUPPORT_FILES_PERMS=	${SMBPASSWD_FILE}
SUPPORT_FILES_PERMS+=	${EXAMPLESDIR}/adduser.sh ${SAMBA_ETCDIR}/adduser \
			${ROOT_USER} ${ROOT_GROUP} 0555
SUPPORT_FILES_PERMS+=	${EXAMPLESDIR}/deluser.sh ${SAMBA_ETCDIR}/deluser \
			${ROOT_USER} ${ROOT_GROUP} 0555
RCD_SCRIPTS=		samba nmbd smbd
OWN_DIRS=		${SAMBA_ETCDIR} ${SAMBA_LOCKDIR}
OWN_DIRS_PERMS=		${SAMBA_PRIVATE} ${ROOT_USER} ${ROOT_GROUP} 0500

.if !defined(MKTEMP)
MKTEMP!=	${TYPE} mktemp 2>&1 | \
		${AWK} '/not found/ { print "mktemp"; exit } { print $$3 }'
MAKEFLAGS+=	MKTEMP=${MKTEMP:Q}
.endif
.if !defined(PWD_MKDB)
PWD_MKDB!=	${TYPE} pwd_mkdb 2>&1 | \
		${AWK} '/not found/ { print "pwd_mkdb"; exit } { print $$3 }'
MAKEFLAGS+=	PWD_MKDB=${PWD_MKDB:Q}
.endif
FILES_SUBST+=	MKTEMP=${MKTEMP:Q}
FILES_SUBST+=	PWD_MKDB=${PWD_MKDB:Q}

REPLACE_PERL=		script/findsmb.in

# Remove irrelevant files for this package.
post-extract:
	${FIND} ${WRKDIR}/${DISTNAME} -name ".cvsignore" -print |	\
		${XARGS} ${RM} -f
	${RM} -r ${WRKDIR}/${DISTNAME}/docs/textdocs/outdated
	${RM} -r ${WRKDIR}/${DISTNAME}/examples/VFS
	${RM} -r ${WRKDIR}/${DISTNAME}/examples/appliance
	${RM} -r ${WRKDIR}/${DISTNAME}/examples/autofs
	${RM} -r ${WRKDIR}/${DISTNAME}/examples/dce-dfs
	${RM} -r ${WRKDIR}/${DISTNAME}/examples/libsmbclient
	${RM} -r ${WRKDIR}/${DISTNAME}/examples/smbchartool
	${RM} -r ${WRKDIR}/${DISTNAME}/examples/svr4-startup

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/adduser.sh > ${WRKDIR}/adduser.sh
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/deluser.sh > ${WRKDIR}/deluser.sh

post-install:
	# Install Samba documentation.
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKDIR}/${DISTNAME}/docs;					\
	for file in announce textdocs/* Registry/*.reg; do		\
		${INSTALL_DATA} $$file ${DOCDIR};			\
	done

	# Install Samba examples.
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/adduser.sh ${EXAMPLESDIR}/adduser.sh
	${INSTALL_SCRIPT} ${WRKDIR}/deluser.sh ${EXAMPLESDIR}/deluser.sh
	${CP} -R ${WRKDIR}/${DISTNAME}/examples/* ${EXAMPLESDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
	${CHMOD} -R ugo-w ${EXAMPLESDIR}

	${INSTALL_SCRIPT} ${WRKSRC}/script/convert_smbpasswd		\
		${EXAMPLESDIR}/misc
	${INSTALL_SCRIPT} ${WRKSRC}/script/mksmbpasswd.sh		\
		${PREFIX}/sbin/mksmbpasswd

.include "../../devel/readline/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
