# $NetBSD: Makefile,v 1.83 2002/06/14 17:04:13 taca Exp $

DISTNAME=		samba-2.2.4
PKGREVISION=		1
WRKSRC=			${WRKDIR}/${DISTNAME}/source
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.samba.org/pub/samba/ \
			ftp://ring.asahi-net.or.jp/pub/net/samba/ \
			ftp://samba.anu.edu.au/pub/samba/ \
			http://de.samba.org/samba/ftp/ \
			ftp://ftp.sunet.se/pub/unix/utilities/samba/
COUNTRY_MIRRORS=	au1 ca fi fr de it pl ru sg se us1 us6
.for COUNTRY in ${COUNTRY_MIRRORS}
MASTER_SITES+=		ftp://${COUNTRY}.samba.org/pub/samba/
.endfor

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.samba.org/
COMMENT=		SMB/CIFS protocol server suite for UNIX

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_BUILDLINK_ONLY=	# defined
USE_GNU_READLINE=	# uses rl_event_hook interface to GNU readline

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	samba

VARDIR?=		/var
SAMBA_ETCDIR?=		${PKG_SYSCONFDIR}
SAMBA_DATADIR=		${PREFIX}/share
SAMBA_LOCKDIR?=		${VARDIR}/db/samba
SAMBA_LOGDIR?=		${VARDIR}/log
SAMBA_PIDDIR?=		${VARDIR}/run
SAMBA_PRIVATE?=		${SAMBA_ETCDIR}/private

MAKE_ENV+=		ETCDIR=${SAMBA_ETCDIR}
MAKE_ENV+=		LOGDIR=${SAMBA_LOGDIR}

CONFIGURE_ARGS+=	--localstatedir=${VARDIR}
CONFIGURE_ARGS+=	--sbindir=${PREFIX}/sbin
CONFIGURE_ARGS+=	--with-configdir=${SAMBA_ETCDIR}
CONFIGURE_ARGS+=	--with-codepagedir=${SAMBA_DATADIR}/samba/codepages
CONFIGURE_ARGS+=	--with-datadir=${SAMBA_DATADIR}
CONFIGURE_ARGS+=	--with-lockdir=${SAMBA_LOCKDIR}
CONFIGURE_ARGS+=	--with-piddir=${SAMBA_PIDDIR}
CONFIGURE_ARGS+=	--with-privatedir=${SAMBA_PRIVATE}
CONFIGURE_ARGS+=	--with-swatdir=${SAMBA_DATADIR}/samba/swat

CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--with-ssl
CONFIGURE_ARGS+=	--with-sslinc=${BUILDLINK_DIR}
CFLAGS+=		-I${BUILDLINK_DIR}/include/openssl	# ssl.h, err.h

CONFIGURE_ENV+=		ac_cv_lib_curses_tgetent=no

.if defined(USE_CUPS) && (${USE_CUPS} == "YES")
.include "../../print/cups/buildlink.mk"
BUILD_DEFS+=		USE_CUPS
.endif

.if defined(USE_PAM)
.include "../../security/PAM/buildlink.mk"
BUILD_DEFS+=		USE_PAM
CONFIGURE_ARGS+=	--with-pam
.endif

.if defined(SAMBA_USE_LDAP) && ${SAMBA_USE_LDAP} == "YES"
.include "../../databases/openldap/buildlink.mk"
BUILD_DEFS+=		SAMBA_USE_LDAP
CONFIGURE_ARGS+=	--with-ldapsam
PLIST_SUBST+=		SAMBA_LDAP=""
.else
PLIST_SUBST+=		SAMBA_LDAP="@comment "
MESSAGE_SRC=		${.CURDIR}/MESSAGE.smbpasswd
SMBPASSWD_FILE=		/dev/null ${SAMBA_PRIVATE}/smbpasswd		\
			${ROOT_USER} ${ROOT_GROUP} 0700
.endif

# The following are Linux-only options.
CONFIGURE_ARGS+=	--without-smbwrapper
CONFIGURE_ARGS+=	--without-smbmount

DOCDIR=			${PREFIX}/share/doc/samba
HTMLDIR=		${PREFIX}/share/doc/html/samba
EXAMPLESDIR=		${PREFIX}/share/examples/samba

FILES_SUBST=		SAMBA_PRIVATE=${SAMBA_PRIVATE}
FILES_SUBST+=		SAMBA_LOCKDIR=${SAMBA_LOCKDIR}
FILES_SUBST+=		SAMBA_LOGDIR=${SAMBA_LOGDIR}
FILES_SUBST+=		SAMBA_ETCDIR=${SAMBA_ETCDIR}
MESSAGE_SUBST+=		SAMBA_ETCDIR=${SAMBA_ETCDIR}
MESSAGE_SUBST+=		ROOT_GROUP=${ROOT_GROUP}
MESSAGE_SUBST+=		ROOT_USER=${ROOT_USER}

CONF_FILES=		${EXAMPLESDIR}/smb.conf.sample ${SAMBA_ETCDIR}/smb.conf
SUPPORT_FILES_PERMS=	${SMBPASSWD_FILE}
RCD_SCRIPTS=		samba nmbd smbd
OWN_DIRS=		${SAMBA_ETCDIR} ${SAMBA_LOCKDIR}
OWN_DIRS_PERMS=		${SAMBA_PRIVATE} ${ROOT_USER} ${ROOT_GROUP} 0500

INSTALL_EXTRA_TMPL=	${PKGDIR}/INSTALL

post-extract:
	${FIND} ${WRKDIR}/${DISTNAME} -name ".cvsignore" -print |	\
		${XARGS} ${RM} -f
	${RM} -r ${WRKDIR}/${DISTNAME}/docs/textdocs/outdated

pre-install:
	@for script in ${RCD_SCRIPTS}; do				\
		${SED} ${FILES_SUBST_SED} ${FILESDIR}/$${script}.sh	\
			> ${WRKDIR}/$${script};				\
	done

post-install:
	# Install Samba documentation.
	${INSTALL_DATA_DIR} ${DOCDIR} ${HTMLDIR}
	cd ${WRKDIR}/${DISTNAME}/docs;					\
		${INSTALL_DATA} announce textdocs/* ${DOCDIR};		\
		${INSTALL_DATA} Registry/*.reg ${DOCDIR};		\
		${INSTALL_DATA} faq/*.html ${HTMLDIR}

	# Install Samba examples.
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${CP} -R ${WRKDIR}/${DISTNAME}/examples/* ${EXAMPLESDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
	${CHMOD} -R ugo-w ${EXAMPLESDIR}

	for script in ${RCD_SCRIPTS}; do				\
		${INSTALL_SCRIPT} ${WRKDIR}/$${script}			\
			${PREFIX}/etc/rc.d/$${script};			\
	done
	${INSTALL_SCRIPT} ${WRKSRC}/script/convert_smbpasswd ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/script/mksmbpasswd.sh		\
		${PREFIX}/sbin/mksmbpasswd

	@${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/smb.conf.sample > ${WRKDIR}/smb.conf.sample
	${INSTALL_DATA} ${WRKDIR}/smb.conf.sample ${EXAMPLESDIR}

.include "../../devel/readline/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
