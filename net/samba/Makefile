# $NetBSD: Makefile,v 1.50 2001/05/22 21:49:28 jlam Exp $

DISTNAME=		samba-2.2.0
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

USE_LIBINTL=		# defined
USE_SSL=		# defined

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_GNU_READLINE=	# uses rl_event_hook interface to GNU readline

.include "../../mk/bsd.prefs.mk"
.include "../../devel/readline/Makefile.readline"

CFLAGS+=		-I${WRKINCDIR}
LDFLAGS+=		-L${WRKLIBDIR}

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
CONFIGURE_ARGS+=	--with-sslinc=${SSLBASE}
CONFIGURE_ENV+=		ac_cv_lib_ncurses_tgetent=no
CONFIGURE_ENV+=		ac_cv_lib_curses_tgetent=no

CPPFLAGS+=		-I${SSLBASE}/include/openssl	# ssl.h, err.h

.if defined(SAMBA_WITH_CUPS)
CONFIGURE_ARGS+=	--with-cups
DEPENDS+=		cups>=1.1.1:../../print/cups
CPPFLAGS+=		-I${LOCALBASE}/include
.endif

.if defined(USE_PAM)
CONFIGURE_ARGS+=	--with-pam
DEPENDS+=		PAM-*:../../security/PAM
CPPFLAGS+=		-I${LOCALBASE}/include
.endif

# The following are Linux-only options.
CONFIGURE_ARGS+=	--without-smbwrapper
CONFIGURE_ARGS+=	--without-smbmount

CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

INSTALL_FILE=		${WRKDIR}/INSTALL
DEINSTALL_FILE=		${WRKDIR}/DEINSTALL

DOCDIR=			${PREFIX}/share/doc/samba
HTMLDIR=		${PREFIX}/share/doc/html/samba

post-extract:
	${FIND} ${WRKDIR}/${DISTNAME} -name ".cvsignore" -exec ${RM} -f {} \;

pre-install:
	for file in nmbd.sh smbd.sh; do					\
		${SED}	-e "s,@PREFIX@,${PREFIX},g"			\
			-e "s,@ECHO@,${ECHO},g"				\
			${FILESDIR}/$${file} > ${WRKDIR}/$${file};	\
	done
	${SED}	-e "s|@SAMBA_PRIVATE@|${SAMBA_PRIVATE}|g"		\
		-e "s|@SAMBA_LOCKDIR@|${SAMBA_LOCKDIR}|g"		\
		-e "s|@SAMBA_ETCDIR@|${SAMBA_ETCDIR}|g"			\
		-e "s|@CAT@|${CAT}|g"					\
		-e "s|@CHMOD@|${CHMOD}|g"				\
		-e "s|@CHOWN@|${CHOWN}|g"				\
		-e "s|@CP@|${CP}|g"					\
		-e "s|@MKDIR@|${MKDIR}|g"				\
		-e "s|@RM@|${RM}|g"					\
		${PKGDIR}/INSTALL > ${INSTALL_FILE}
	${SED}	-e "s|@SAMBA_PRIVATE@|${SAMBA_PRIVATE}|g"		\
		-e "s|@SAMBA_LOCKDIR@|${SAMBA_LOCKDIR}|g"		\
		-e "s|@SAMBA_ETCDIR@|${SAMBA_ETCDIR}|g"			\
		-e "s|@CAT@|${CAT}|g"					\
		-e "s|@RM@|${RM}|g"					\
		-e "s|@RMDIR@|${RMDIR}|g"				\
		-e "s|@TRUE@|${TRUE}|g"					\
		${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}

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

	${SED}	-e "s|@SAMBA_LOGDIR@|${SAMBA_LOGDIR}|g"			\
		-e "s|@SAMBA_ETCDIR@|${SAMBA_ETCDIR}|g"			\
		-e "s|@PREFIX@|${PREFIX}|g"				\
		${FILESDIR}/smb.conf.sample > ${WRKDIR}/smb.conf.sample
	${INSTALL_DATA} ${WRKDIR}/smb.conf.sample ${PREFIX}/share/examples/samba

	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
