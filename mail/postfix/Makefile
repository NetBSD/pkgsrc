# $NetBSD: Makefile,v 1.289 2016/03/05 11:28:50 jperkin Exp $

.include "../../mail/postfix/Makefile.common"

COMMENT=	Postfix SMTP server and tools
PKGREVISION=	3

CONFLICTS+=	courier-mta-[0-9]* fastforward>=0.51nb2 sendmail-[0-9]*
CONFLICTS+=	esmtp>=1.2 nullmailer-[0-9]*

USE_TOOLS+=	perl

SPECIAL_PERMS+=	sbin/postdrop postfix maildrop 2555
SPECIAL_PERMS+=	sbin/postqueue postfix maildrop 2555

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
OWN_DIRS_PERMS+=	${POSTFIX_DATA_DIR} postfix postfix 0700
MAKE_DIRS+=		${METADIR}/dynamicmaps.cf.d ${METADIR}/postfix-files.d

PKG_GROUPS?=		postfix maildrop
PKG_USERS?=		postfix:postfix
PKG_GECOS.postfix=	Postfix User
PKG_HOME.postfix=	${POSTFIX_QUEUE_DIR}

CONF_FILES=		# empty
.for i in main.cf master.cf
CONF_FILES+=		${EXAMPLEDIR}/${i} ${PKG_SYSCONFDIR}/${i}
.endfor
CONF_FILES_PERMS=	# empty

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/mailer.conf
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_STAGE.paths=	post-patch

INSTALLATION_DIRS+=	${LIBEXECDIR} ${METADIR} ${SHLIBDIR} ${EXAMPLEDIR} ${DOCDIR}

post-extract:
	cp ${FILESDIR}/mailer.conf ${WRKDIR}/mailer.conf
	rm -f ${WRKSRC}/auxiliary/MacOSX/Postfix.StartupItem/Postfix

post-build:
.if !empty(PKG_OPTIONS:Msasl)
	${ECHO} "pwcheck_method: ${PWCHECK_METHOD}" > ${WRKDIR}/smtpd.conf
.endif

do-install:
	rm -f ${WRKSRC}/conf/*.orig
.if !empty(PKG_OPTIONS:Msasl)
	${INSTALL_DATA} ${WRKDIR}/smtpd.conf ${DESTDIR}${EXAMPLEDIR}
.endif
	cd ${WRKSRC} && ${SETENV} LD_LIBRARY_PATH=${WRKSRC}/lib sh		\
		./postfix-install -non-interactive				\
		${DESTDIR_INSTALLOPTIONS} config_directory="${EXAMPLEDIR}"
	${INSTALL_DATA} ${WRKDIR}/mailer.conf \
		${DESTDIR}${EXAMPLEDIR}/mailer.conf
	${INSTALL_SCRIPT} ${WRKSRC}/auxiliary/qshape/qshape.pl \
		${DESTDIR}${PREFIX}/sbin/qshape
	${INSTALL_MAN} ${WRKSRC}/man/man1/qshape.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
