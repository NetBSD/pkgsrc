# $NetBSD: Makefile,v 1.1.1.1 2000/08/30 17:29:44 kei Exp $

DISTNAME=		samba-2.0.7-ja-1.2
WRKSRC=			${WRKDIR}/${DISTNAME}/source
CATEGORIES=		japanese
MASTER_SITES=		ftp://ftp.samba.gr.jp/pub/samba-jp/samba-2.0.7-ja/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		oishi@ims.ac.jp
HOMEPAGE=		http://www.samba.gr.jp/

BUILD_DEPENDS+=		${LOCALBASE}/bin/autoreconf:../../devel/autoconf

.if !exists(/usr/include/readline.h)
DEPENDS+=		readline>=4.0:../../devel/readline
.endif

GNU_CONFIGURE=		# defined

.include "../../mk/bsd.prefs.mk"

STARTUP_SCRIPT=		${PREFIX}/etc/rc.d/samba.sh.sample
SAMPLE_CONFIG=		${PREFIX}/share/examples/samba/smb.conf.sample
SAMBA_LOGDIR=		/var/log
SAMBA_LOCKDIR=		/var/run/samba
SAMBA_ETCDIR?=		/etc/samba
SAMBA_PRIVATE?=		${SAMBA_ETCDIR}/private

.if ${OPSYS} == "SunOS"
ROOT_GROUP?=		root
.else
ROOT_GROUP?=		wheel
.endif

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
		-e "s,@ROOT_GROUP@,${ROOT_GROUP},g" \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	${SED}	-e "s,@SAMBA_PRIVATE@,${SAMBA_PRIVATE},g" \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
