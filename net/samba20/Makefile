# $NetBSD: Makefile,v 1.3 2001/11/21 17:17:44 jlam Exp $

DISTNAME=		samba-2.0.10
WRKSRC=			${WRKDIR}/${DISTNAME}/source
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.samba.org/pub/samba/old-versions/ \
			ftp://samba.anu.edu.au/pub/samba/old-versions/ \
			ftp://de.samba.org/samba.org/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.samba.org/
COMMENT=		SMB/CIFS protocol server suite for UNIX

BUILD_USES_MSGFMT=	# defined
GNU_CONFIGURE=		# defined
USE_BUILDLINK_ONLY=	# defined

.include "../../mk/bsd.prefs.mk"

SAMBA_LOGDIR?=		/var/log
SAMBA_LOCKDIR?=		/var/run/samba
SAMBA_ETCDIR?=		${CONFDIR}/samba
SAMBA_PRIVATE?=		${SAMBA_ETCDIR}/private
SAMBA_DATADIR=		${PREFIX}/share

MAKE_ENV+=		CONFIGDIR=${SAMBA_ETCDIR}

CONFIGURE_ARGS+=	--localstatedir=${SAMBA_LOGDIR}
CONFIGURE_ARGS+=	--with-lockdir=${SAMBA_LOCKDIR}
CONFIGURE_ARGS+=	--with-privatedir=${SAMBA_PRIVATE}
CONFIGURE_ARGS+=	--with-swatdir=${PREFIX}/share/swat
CONFIGURE_ARGS+=	--with-sambabook=${PREFIX}/share/swat/using_samba

CONFIGURE_ARGS+=	--with-ssl
CONFIGURE_ARGS+=	--with-sslinc=${BUILDLINK_DIR}
CFLAGS+=		-I${BUILDLINK_DIR}/include/openssl      # ssl.h, err.h

.if defined(SAMBA_WITH_CUPS)
.include "../../print/cups/buildlink.mk"
.endif

.if defined(USE_PAM)
.include "../../security/PAM/buildlink.mk"
CONFIGURE_ARGS+=	--with-pam
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
MESSAGE_SUBST+=		ETCDIR=${SAMBA_ETCDIR}

CONF_FILES=		${EXAMPLESDIR}/smb.conf.sample ${SAMBA_ETCDIR}/smb.conf
RCD_SCRIPTS=		samba nmbd smbd
MAKE_DIRS=		${SAMBA_LOCKDIR}
OWN_DIRS=		${SAMBA_ETCDIR} ${SAMBA_PRIVATE}

INSTALL_EXTRA_TMPL=	${PKGDIR}/INSTALL

pre-install:
	for script in ${RCD_SCRIPTS}; do				\
		${SED} ${FILES_SUBST_SED} ${FILESDIR}/$${script}.sh	\
			> ${WRKDIR}/$${script};				\
	done

post-install:
	# Install Samba documentation.
	${INSTALL_DATA_DIR} ${DOCDIR} ${HTMLDIR}
	cd ${WRKDIR}/${DISTNAME}/docs;					\
		${INSTALL_DATA} announce *.reg textdocs/* ${DOCDIR};	\
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
	${MV} ${PREFIX}/bin/convert_smbpasswd ${PREFIX}/sbin/convert_smbpasswd
	${INSTALL_SCRIPT} ${WRKSRC}/script/mksmbpasswd.sh		\
		${PREFIX}/sbin/mksmbpasswd

	${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/smb.conf.sample > ${WRKDIR}/smb.conf.sample
	${INSTALL_DATA} ${WRKDIR}/smb.conf.sample ${EXAMPLESDIR}

	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
