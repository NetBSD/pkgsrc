# $NetBSD: Makefile,v 1.337 2022/07/21 15:08:39 taca Exp $

.include "../../mail/postfix/Makefile.common"

COMMENT=	Fast, easy to administer, and secure mail transfer agent

CONFLICTS+=	courier-mta-[0-9]* fastforward>=0.51nb2 sendmail-[0-9]*
CONFLICTS+=	esmtp>=1.2 nullmailer-[0-9]*

USE_TOOLS+=	perl pkg-config m4

SPECIAL_PERMS+=	sbin/postdrop ${POSTFIX_USER} ${MAILDROP_GROUP} 2555
SPECIAL_PERMS+=	sbin/postqueue ${POSTFIX_USER} ${MAILDROP_GROUP} 2555

REPLACE_PERL+=	auxiliary/qshape/qshape.pl

# options.mk appends to CCARGS and AUXLIBS the options needed to build
# Postfix with support for various add-on modules.
#
.include "options.mk"

FILES_SUBST+=		EXAMPLEDIR=${EXAMPLEDIR}
MESSAGE_SUBST+=		EXAMPLEDIR=${EXAMPLEDIR}
MESSAGE_SUBST+=		DOCDIR=${DOCDIR}

MESSAGE_SRC+=		${PKGDIR}/MESSAGE
.if exists(${PKGDIR}/MESSAGE.${OPSYS})
MESSAGE_SRC+=		${PKGDIR}/MESSAGE.${OPSYS}
.endif
PLIST_SRC+=		${PKGDIR}/PLIST

RCD_SCRIPTS=		postfix
OWN_DIRS+=		${POSTFIX_QUEUE_DIR} ${POSTFIX_QUEUE_DIR}/etc
OWN_DIRS_PERMS+=	${POSTFIX_DATA_DIR} ${POSTFIX_USER} ${POSTFIX_GROUP} 0700
MAKE_DIRS+=		${METADIR}/dynamicmaps.cf.d ${METADIR}/postfix-files.d

PKG_GROUPS?=		${POSTFIX_GROUP} ${MAILDROP_GROUP}
PKG_USERS?=		${POSTFIX_USER}:${POSTFIX_GROUP}

PKG_GECOS.${POSTFIX_USER}=	Postfix User
PKG_HOME.${POSTFIX_USER}=	${POSTFIX_QUEUE_DIR}

CONF_FILES=		# empty
.for i in main.cf master.cf
CONF_FILES+=		${EXAMPLEDIR}/${i} ${PKG_SYSCONFDIR}/${i}
.endfor
CONF_FILES_PERMS=	# empty

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/mailer.conf
SUBST_VARS.paths=	PREFIX
SUBST_STAGE.paths=	pre-configure

INSTALLATION_DIRS+=	${LIBEXECDIR} ${METADIR} ${SHLIBDIR} ${EXAMPLEDIR} ${DOCDIR}

post-extract:
	${CP} ${FILESDIR}/mailer.conf ${WRKDIR}/mailer.conf
	${RM} -f ${WRKSRC}/auxiliary/MacOSX/Postfix.StartupItem/Postfix

post-build:
.if !empty(PKG_OPTIONS:Msasl)
	${ECHO} "pwcheck_method: ${PWCHECK_METHOD}" > ${WRKDIR}/smtpd.conf
.endif

do-install:
	${RM} -f ${WRKSRC}/conf/*.orig
.if !empty(PKG_OPTIONS:Msasl)
	${INSTALL_DATA} ${WRKDIR}/smtpd.conf ${DESTDIR}${EXAMPLEDIR}
.endif
	cd ${WRKSRC} && ${SETENV} LD_LIBRARY_PATH=${WRKSRC}/lib \
		DYLD_LIBRARY_PATH=${WRKSRC}/lib \
		${SH} ./postfix-install -non-interactive \
		${DESTDIR_INSTALLOPTIONS} config_directory="${EXAMPLEDIR}"
	${INSTALL_DATA} ${WRKDIR}/mailer.conf \
		${DESTDIR}${EXAMPLEDIR}/mailer.conf
	${INSTALL_SCRIPT} ${WRKSRC}/auxiliary/qshape/qshape.pl \
		${DESTDIR}${PREFIX}/sbin/qshape
	${INSTALL_MAN} ${WRKSRC}/man/man1/qshape.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.for dir in ${POSTFIX_QUEUE_SUBDIR}
	${RMDIR} ${DESTDIR}${POSTFIX_QUEUE_DIR}/${dir}
.endfor
.if ${OPSYS} == "Darwin"
	for f in ${DESTDIR}${PREFIX}/lib/postfix/lib*.dylib; do \
		install_name_tool -id `${ECHO} $$f | ${SED} -e 's,${DESTDIR},,g'` $$f; \
	done
	for f in ${DESTDIR}${PREFIX}/libexec/postfix/* ${DESTDIR}${PREFIX}/sbin/*; do \
		install_name_tool \
			-change @rpath/libpostfix-dns.dylib ${PREFIX}/lib/postfix/libpostfix-dns.dylib \
			-change @rpath/libpostfix-global.dylib ${PREFIX}/lib/postfix/libpostfix-global.dylib \
			-change @rpath/libpostfix-master.dylib ${PREFIX}/lib/postfix/libpostfix-master.dylib \
			-change @rpath/libpostfix-tls.dylib ${PREFIX}/lib/postfix/libpostfix-tls.dylib \
			-change @rpath/libpostfix-util.dylib ${PREFIX}/lib/postfix/libpostfix-util.dylib \
			$$f; \
	done
.endif

.include "../../mk/bsd.pkg.mk"
