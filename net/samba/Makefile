# $NetBSD: Makefile,v 1.130 2004/10/03 00:17:58 tv Exp $

DISTNAME=		samba-3.0.7
PKGREVISION=	1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.samba.org/pub/samba/old-versions/ \
			ftp://ring.asahi-net.or.jp/pub/net/samba/old-versions/ \
			ftp://samba.anu.edu.au/pub/samba/old-versions/ \
			ftp://ftp.sunet.se/pub/unix/utilities/samba/old-versions/
COUNTRY_MIRRORS=	au1 ca fi fr it pl ru sg se us1 us6
.for COUNTRY in ${COUNTRY_MIRRORS}
MASTER_SITES+=		ftp://${COUNTRY}.samba.org/pub/samba/old-versions/
.endfor

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://www.samba.org/
COMMENT=		SMB/CIFS protocol server suite

CONFLICTS+=		ja-samba-[0-9]* pam-smbpass-[0-9]* winbind-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME}/source
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PERL="${PERL5}"

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	samba
PKG_SYSCONFVAR=		samba

SAMBA_ETCDIR?=		${PKG_SYSCONFDIR}
SAMBA_LIBDIR?=		${PREFIX}/lib/samba
SAMBA_LOCKDIR?=		${SAMBA_VARDIR}/db/samba
SAMBA_LOGDIR?=		${SAMBA_VARDIR}/log
SAMBA_PIDDIR?=		${SAMBA_VARDIR}/run
SAMBA_PRIVATE?=		${SAMBA_ETCDIR}/private
SAMBA_VARDIR?=		/var

FILES_SUBST=		SAMBA_ETCDIR=${SAMBA_ETCDIR}
FILES_SUBST+=		SAMBA_LOCKDIR=${SAMBA_LOCKDIR}
FILES_SUBST+=		SAMBA_LOGDIR=${SAMBA_LOGDIR}
FILES_SUBST+=		SAMBA_PIDDIR=${SAMBA_PIDDIR}
FILES_SUBST+=		SAMBA_PRIVATE=${SAMBA_PRIVATE}
FILES_SUBST+=		SAMBA_VARDIR=${SAMBA_VARDIR}

CONFIGURE_ARGS+=	--with-configdir=${SAMBA_ETCDIR}
CONFIGURE_ARGS+=	--with-libdir=${SAMBA_LIBDIR}
CONFIGURE_ARGS+=	--with-lockdir=${SAMBA_LOCKDIR}
CONFIGURE_ARGS+=	--with-logfilebase=${SAMBA_LOGDIR}
CONFIGURE_ARGS+=	--with-piddir=${SAMBA_PIDDIR}
CONFIGURE_ARGS+=	--with-privatedir=${SAMBA_PRIVATE}
CONFIGURE_ARGS+=	--localstatedir=${SAMBA_VARDIR}

CONFIGURE_ARGS+=	--with-swatdir=${PREFIX}/share/samba/swat
CONFIGURE_ARGS+=	--with-libsmbclient
CONFIGURE_ARGS+=	--with-winbind

.include "../../converters/libiconv/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libiconv=${BUILDLINK_PREFIX.iconv}

USE_GNU_READLINE=	yes
.include "../../devel/readline/buildlink3.mk"
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}

.include "options.mk"

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

.if !empty(NSS_WINBIND)
PLIST_SUBST+=	NSS_WINBIND=lib/${NSS_WINBIND}
.else
PLIST_SUBST+=	NSS_WINBIND="@comment no NSS winbind module"
.endif
.if !empty(NSS_WINS)
PLIST_SUBST+=	NSS_WINS=lib/${NSS_WINS}
.else
PLIST_SUBST+=	NSS_WINS="@comment no NSS WINS module"
.endif

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

USE_PKGINSTALL=		yes
CONF_FILES=		${EGDIR}/smb.conf.default ${SAMBA_ETCDIR}/smb.conf
SUPPORT_FILES_PERMS=	${EGDIR}/adduser.sh ${SAMBA_ETCDIR}/adduser	\
			${ROOT_USER} ${ROOT_GROUP} 0755
SUPPORT_FILES_PERMS+=	${EGDIR}/deluser.sh ${SAMBA_ETCDIR}/deluser	\
			${ROOT_USER} ${ROOT_GROUP} 0755
MAKE_DIRS=		${SAMBA_VARDIR} ${SAMBA_LOGDIR} ${SAMBA_PIDDIR}
OWN_DIRS=		${SAMBA_ETCDIR} ${SAMBA_LOCKDIR}
OWN_DIRS_PERMS=		${SAMBA_PRIVATE} ${ROOT_USER} ${ROOT_GROUP} 0700
RCD_SCRIPTS=		samba nmbd smbd winbindd

INSTALL_LIBRARY=	\
	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/adduser.sh > ${WRKDIR}/adduser.sh
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/deluser.sh > ${WRKDIR}/deluser.sh

post-install:
	-cd ${SAMBA_LIBDIR} && ln -s libsmbclient.so libsmbclient.so.0
	for d in auth idmap pdb rpc; do					\
		${RMDIR} ${SAMBA_LIBDIR}/$$d;				\
	done
.if !empty(NSS_WINBIND)
	${INSTALL_LIBRARY} ${WRKSRC}/nsswitch/${NSS_WINBIND} ${PREFIX}/lib
.endif
.if !empty(NSS_WINS)
	${INSTALL_LIBRARY} ${WRKSRC}/nsswitch/${NSS_WINS} ${PREFIX}/lib
.endif
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/../docs/registry; for file in *.reg; do		\
		${INSTALL_DATA} $$file ${DOCDIR}/$$file;		\
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
.if !empty(PKG_OPTIONS:MPAM)
	${INSTALL_DATA_DIR} ${PAM_INSTMODULEDIR}
	${INSTALL_LIBRARY} ${WRKSRC}/bin/pam_smbpass.so ${PAM_INSTMODULEDIR}
	${INSTALL_LIBRARY} ${WRKSRC}/nsswitch/pam_winbind.so ${PAM_INSTMODULEDIR}
	${INSTALL_DATA} ${WRKSRC}/pam_smbpass/README			\
		${DOCDIR}/README.pam_smbpass
	${INSTALL_DATA_DIR} ${EGDIR}/pam_smbpass
	cd ${WRKSRC}/pam_smbpass/samples; for file in [a-z]*; do	\
		${INSTALL_DATA} $${file} ${EGDIR}/pam_smbpass/$${file};	\
	done
.endif

.include "../../mk/bsd.pkg.mk"
