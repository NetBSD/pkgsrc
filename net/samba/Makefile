# $NetBSD: Makefile,v 1.121 2004/04/21 21:09:32 cube Exp $

DISTNAME=		samba-3.0.2a
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.samba.org/pub/samba/ \
			ftp://ring.asahi-net.or.jp/pub/net/samba/ \
			ftp://samba.anu.edu.au/pub/samba/ \
			ftp://ftp.sunet.se/pub/unix/utilities/samba/
COUNTRY_MIRRORS=	au1 ca fi fr de it pl ru sg se us1 us6
.for COUNTRY in ${COUNTRY_MIRRORS}
MASTER_SITES+=		ftp://${COUNTRY}.samba.org/pub/samba/
.endfor
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://www.samba.org/
COMMENT=		SMB/CIFS protocol server suite

CONFLICTS+=		pam-smbpass-[0-9]* winbind-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME}/source
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PERL="${PERL5}"
PLIST_SRC=		# empty

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
CONFIGURE_ARGS+=	--with-lockdir=${SAMBA_LOCKDIR}
CONFIGURE_ARGS+=	--with-logfilebase=${SAMBA_LOGDIR}
CONFIGURE_ARGS+=	--with-piddir=${SAMBA_PIDDIR}
CONFIGURE_ARGS+=	--with-privatedir=${SAMBA_PRIVATE}
CONFIGURE_ARGS+=	--localstatedir=${SAMBA_VARDIR}
CONFIGURE_ARGS+=	--libdir=${SAMBA_LIBDIR}

CONFIGURE_ARGS+=	--with-swatdir=${PREFIX}/share/samba/swat
CONFIGURE_ARGS+=	--with-libsmbclient
CONFIGURE_ARGS+=	--with-winbind

.include "../../converters/libiconv/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libiconv=${BUILDLINK_PREFIX.iconv}

USE_GNU_READLINE=	yes
.include "../../devel/readline/buildlink3.mk"
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}

.if defined(SAMBA_WITH_ADS) && !empty(SAMBA_WITH_ADS:M[yY][eE][sS])
.  include "../../mk/krb5.buildlink3.mk"
SAMBA_USE_LDAP=		# defined
CONFIGURE_ARGS+=	--with-ads
CONFIGURE_ARGS+=	--with-krb5=${KRB5BASE}
.else
CONFIGURE_ARGS+=	--without-ads
CONFIGURE_ARGS+=	--without-krb5
.endif
BUILD_DEFS+=		SAMBA_WITH_ADS

.if defined(USE_CUPS) && !empty(USE_CUPS:M[yY][eE][sS])
.  include "../../print/cups/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cups
.else
CONFIGURE_ARGS+=	--disable-cups
.endif
BUILD_DEFS+=		USE_CUPS

.if defined(USE_PAM)
.  include "../../security/PAM/module.mk"
CONFIGURE_ARGS+=	--with-pam
CONFIGURE_ARGS+=	--with-pam_smbpass
PLIST_SRC+=		${PKGDIR}/PLIST.pam
.endif
BUILD_DEFS+=		USE_PAM

.if defined(SAMBA_USE_LDAP) || (defined(USE_OPENLDAP) && !empty(USE_OPENLDAP:M[yY][eE][sS]))
.  include "../../databases/openldap/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap
.  if defined(SAMBA_USE_LDAP_COMPAT) && \
   !empty(SAMBA_USE_LDAP_COMPAT:M[yY][eE][sS])
CONFIGURE_ARGS+=	--with-ldapsam
.  endif
.else
CONFIGURE_ARGS+=	--without-ldap
.endif
BUILD_DEFS+=		USE_OPENLDAP
BUILD_DEFS+=		SAMBA_USE_LDAP
BUILD_DEFS+=		SAMBA_USE_LDAP_COMPAT

PLIST_SRC+=		${PKGDIR}/PLIST

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

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-smbmount
PLIST_SUBST+=		SMBMOUNT=
.else
PLIST_SUBST+=		SMBMOUNT="@comment "
.endif

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
	cd ${PREFIX}/lib && ln -s libsmbclient.so libsmbclient.so.0
	${RMDIR} ${SAMBA_LIBDIR}/auth
	${RMDIR} ${SAMBA_LIBDIR}/idmap
	${RMDIR} ${SAMBA_LIBDIR}/pdb
	${RMDIR} ${SAMBA_LIBDIR}/rpc
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_LIBRARY} ${WRKSRC}/nsswitch/libnss_winbind.so ${PREFIX}/lib
	${INSTALL_LIBRARY} ${WRKSRC}/nsswitch/libnss_wins.so ${PREFIX}/lib
	cd ${WRKSRC}/../docs/Registry; for file in *.reg; do		\
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
.if defined(USE_PAM)
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
