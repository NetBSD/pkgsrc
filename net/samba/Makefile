# $NetBSD: Makefile,v 1.72 2001/12/02 06:56:43 jlam Exp $

DISTNAME=		samba-2.2.2
WRKSRC=			${WRKDIR}/${DISTNAME}/source
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.samba.org/pub/samba/ \
			ftp://ring.asahi-net.or.jp/pub/net/samba/ \
			ftp://samba.anu.edu.au/pub/samba/ \
			ftp://de.samba.org/pub/mirror/samba/ \
			ftp://se.samba.org/pub/samba/ \
			ftp://ftp.sunet.se/pub/unix/utilities/samba/

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

SAMBA_LOGDIR?=		/var/log
SAMBA_LOCKDIR?=		/var/run/samba
SAMBA_ETCDIR?=		${PKG_SYSCONFDIR}
SAMBA_PRIVATE?=		${SAMBA_ETCDIR}/private
SAMBA_DATADIR=		${PREFIX}/share

MAKE_ENV+=		ETCDIR=${SAMBA_ETCDIR}
MAKE_ENV+=		LOGDIR=${SAMBA_LOGDIR}

CONFIGURE_ARGS+=	--localstatedir=${SAMBA_LOGDIR}
CONFIGURE_ARGS+=	--sbindir=${PREFIX}/sbin
CONFIGURE_ARGS+=	--with-configdir=${SAMBA_ETCDIR}
CONFIGURE_ARGS+=	--with-codepagedir=${SAMBA_DATADIR}/samba/codepages
CONFIGURE_ARGS+=	--with-datadir=${SAMBA_DATADIR}
CONFIGURE_ARGS+=	--with-lockdir=${SAMBA_LOCKDIR}
CONFIGURE_ARGS+=	--with-privatedir=${SAMBA_PRIVATE}
CONFIGURE_ARGS+=	--with-swatdir=${SAMBA_DATADIR}/samba/swat

CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--with-ssl
CONFIGURE_ARGS+=	--with-sslinc=${BUILDLINK_DIR}
CFLAGS+=		-I${BUILDLINK_DIR}/include/openssl	# ssl.h, err.h

CONFIGURE_ENV+=		ac_cv_lib_curses_tgetent=no

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

post-extract:
	${FIND} ${WRKDIR}/${DISTNAME} -name ".cvsignore" -print |	\
		${XARGS} ${RM} -f
	${RM} -r ${WRKDIR}/${DISTNAME}/docs/textdocs/outdated

pre-install:
	for script in ${RCD_SCRIPTS}; do				\
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

	${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/smb.conf.sample > ${WRKDIR}/smb.conf.sample
	${INSTALL_DATA} ${WRKDIR}/smb.conf.sample ${EXAMPLESDIR}

.include "../../devel/readline/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
