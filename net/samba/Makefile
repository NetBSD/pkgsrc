# $NetBSD: Makefile,v 1.58 2001/06/19 09:03:30 jlam Exp $

DISTNAME=		samba-2.2.0
PKGNAME=		${DISTNAME}nb1
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

#USE_SSL=		# defined

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_BUILDLINK_ONLY=	# defined
USE_GNU_READLINE=	# uses rl_event_hook interface to GNU readline

.include "../../mk/bsd.prefs.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../security/openssl/buildlink.mk"

SAMBA_LOGDIR=		/var/log
SAMBA_LOCKDIR=		/var/run/samba
SAMBA_ETCDIR?=		/etc/samba
SAMBA_PRIVATE?=		${SAMBA_ETCDIR}/private

MAKE_ENV+=		ETCDIR=${SAMBA_ETCDIR}
MAKE_ENV+=		LOGDIR=${SAMBA_LOGDIR}

CONFIGURE_ARGS+=	--localstatedir=${SAMBA_LOGDIR}
CONFIGURE_ARGS+=	--sbindir=${PREFIX}/sbin
CONFIGURE_ARGS+=	--with-configdir=${SAMBA_ETCDIR}
CONFIGURE_ARGS+=	--with-lockdir=${SAMBA_LOCKDIR}
CONFIGURE_ARGS+=	--with-privatedir=${SAMBA_PRIVATE}
CONFIGURE_ARGS+=	--with-swatdir=${PREFIX}/share/swat

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

INSTALL_FILE=		${WRKDIR}/INSTALL
DEINSTALL_FILE=		${WRKDIR}/DEINSTALL

DOCDIR=			${PREFIX}/share/doc/samba
HTMLDIR=		${PREFIX}/share/doc/html/samba

FILES_SUBST=		SAMBA_PRIVATE=${SAMBA_PRIVATE}
FILES_SUBST+=		SAMBA_LOCKDIR=${SAMBA_LOCKDIR}
FILES_SUBST+=		SAMBA_LOGDIR=${SAMBA_LOGDIR}
FILES_SUBST+=		SAMBA_ETCDIR=${SAMBA_ETCDIR}
FILES_SUBST+=		PREFIX=${PREFIX}
FILES_SUBST+=		CAT=${CAT:Q}
FILES_SUBST+=		CHMOD=${CHMOD:Q}
FILES_SUBST+=		CHOWN=${CHOWN:Q}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		ECHO=${ECHO:Q}
FILES_SUBST+=		MKDIR=${MKDIR:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		RMDIR=${RMDIR:Q}
FILES_SUBST+=		TRUE=${TRUE:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

post-extract:
	${FIND} ${WRKDIR}/${DISTNAME} -name ".cvsignore" -print0 |	\
		${XARGS} -0 ${RM} -f

pre-install:
	for file in nmbd.sh smbd.sh; do					\
		${SED} ${FILES_SUBST_SED}				\
			${FILESDIR}/$${file} > ${WRKDIR}/$${file};	\
	done
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}

post-install:
	# Install Samba documentation.
	${INSTALL_DATA_DIR} ${DOCDIR} ${HTMLDIR}
	cd ${WRKDIR}/${DISTNAME}/docs;					\
		${INSTALL_DATA} announce *.reg textdocs/* ${DOCDIR};	\
		${INSTALL_DATA} faq/*.html ${HTMLDIR}

	# Install Samba examples.
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/samba
	${CP} -R ${WRKDIR}/${DISTNAME}/examples/* ${PREFIX}/share/examples/samba
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/examples/samba
	${CHMOD} -R ugo-w ${PREFIX}/share/examples/samba

	${INSTALL_SCRIPT} ${WRKDIR}/nmbd.sh ${PREFIX}/etc/rc.d/nmbd
	${INSTALL_SCRIPT} ${WRKDIR}/smbd.sh ${PREFIX}/etc/rc.d/smbd
	${INSTALL_SCRIPT} ${WRKSRC}/script/mksmbpasswd.sh		\
		${PREFIX}/sbin/mksmbpasswd

	${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/smb.conf.sample > ${WRKDIR}/smb.conf.sample
	${INSTALL_DATA} ${WRKDIR}/smb.conf.sample ${PREFIX}/share/examples/samba

	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
