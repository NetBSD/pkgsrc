# $NetBSD: Makefile,v 1.32 2000/05/02 15:24:08 jlam Exp $

DISTNAME=		samba-2.0.7
WRKSRC=			${WRKDIR}/${DISTNAME}/source
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.samba.org/pub/samba/ \
			http://us1.samba.org/samba/ftp/ \
			ftp://us3.samba.org/pub/mirrors/sambaftp/

MAINTAINER=		bouyer@netbsd.org
HOMEPAGE=		http://www.samba.org/

BUILD_DEPENDS+=		${LOCALBASE}/bin/autoreconf:../../devel/autoconf

.if !exists(/usr/include/readline.h)
DEPENDS+=		readline-4.0:../../devel/readline
.endif

GNU_CONFIGURE=		# defined

.include "../../mk/bsd.prefs.mk"

STARTUP_SCRIPT=		${PREFIX}/etc/rc.d/samba.sh.sample
SAMPLE_CONFIG=		${PREFIX}/share/examples/samba/smb.conf.sample
SAMBA_LOGDIR=		/var/log
SAMBA_LOCKDIR=		/var/run/samba
SAMBA_ETCDIR?=		/etc/samba
SAMBA_PRIVATE?=		${SAMBA_ETCDIR}/private

MAKE_ENV+=		ETCDIR=${SAMBA_ETCDIR}
MAKE_ENV+=		LOGDIR=${SAMBA_LOGDIR}

CONFIGURE_ARGS+=	--with-lockdir=${SAMBA_LOCKDIR} \
			--with-privatedir=${SAMBA_PRIVATE} \
			--with-swatdir=${PREFIX}/share/swat \
			--with-sambabook=${PREFIX}/share/swat/using_samba

PLIST_SUBST+=		SAMBA_PRIVATE=${SAMBA_PRIVATE}

INSTALL_FILE=		${WRKDIR}/INSTALL
DEINSTALL_FILE=		${WRKDIR}/DEINSTALL

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoreconf

post-install:
	# Install Samba documentation.
	#	
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/samba
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/samba/faq
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/samba/textdocs
	cd ${WRKDIR}/${DISTNAME}/docs; \
	for file in \
	    NT4-Locking.reg NT4-Locking.txt NT4_PlainPassword.reg \
	    THANKS Win2000_PlainPassword.reg Win95_PlainPassword.reg \
	    Win98_PlainPassword.reg Win9X-CacheHandling.reg \
	    WindowsTerminalServer.reg announce; do \
		${INSTALL_DATA} $${file} ${PREFIX}/share/doc/samba; \
	done
	for file in ${WRKDIR}/${DISTNAME}/docs/faq/*.html; do \
		${INSTALL_DATA} $${file} ${PREFIX}/share/doc/samba/faq; \
	done
	for file in ${WRKDIR}/${DISTNAME}/docs/textdocs/*; do \
		${INSTALL_DATA} $${file} ${PREFIX}/share/doc/samba/textdocs; \
	done

	# Install Samba examples.
	#	
	${MKDIR} ${PREFIX}/share/examples/samba
	${CP} -R ${WRKDIR}/${DISTNAME}/examples/* ${PREFIX}/share/examples/samba
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/examples/samba
	${CHMOD} -R ugo-w ${PREFIX}/share/examples/samba

	${SED}	-e "s,@PREFIX@,${PREFIX},g" \
		-e "s,@ECHO@,${ECHO},g" \
		< ${FILESDIR}/samba.sh > ${WRKDIR}/samba.sh
	${INSTALL_SCRIPT} ${WRKDIR}/samba.sh ${STARTUP_SCRIPT}

	${SED}	-e 's,@LOGDIR@,${SAMBA_LOGDIR},g' \
		-e 's,@ETCDIR@,${SAMBA_ETCDIR},g' \
		-e 's,@PREFIX@,{PREFIX},g' \
		< ${FILESDIR}/smb.conf.sample > ${WRKDIR}/smb.conf.sample
	${INSTALL_DATA} ${WRKDIR}/smb.conf.sample ${SAMPLE_CONFIG}
	${INSTALL_SCRIPT} ${WRKSRC}/script/mksmbpasswd.sh ${PREFIX}/bin

	${SED}	-e "s,@SAMBA_PRIVATE@,${SAMBA_PRIVATE},g" \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	${SED}	-e "s,@SAMBA_PRIVATE@,${SAMBA_PRIVATE},g" \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
