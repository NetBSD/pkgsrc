# $NetBSD: Makefile,v 1.140 2004/07/19 19:59:16 jlam Exp $

DISTNAME=	postfix-2.1.3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.porcupine.org/mirrors/postfix-release/official/
DIST_SUBDIR=	postfix

PATCHFILES+=		postfix-2.1.1-canonical_classes.diff
PATCH_SITES+=		ftp://ftp.gw.com/pub/people/kim/patches/
PATCH_DIST_STRIP=	-p1

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.postfix.org/
COMMENT=	Postfix SMTP server and tools

CONFLICTS+=	sendmail-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
USE_BUILDLINK3=		yes

.include "../../mk/bsd.prefs.mk"

# POSTFIX_QUEUE_DIR is the default queue directory for Postfix.  This is
# merely a default, and may be changed by setting "queue_directory" in
# ${PKG_SYSCONFDIR}/main.cf.
#
POSTFIX_QUEUE_DIR?=	${VARBASE}/spool/postfix

# CCARGS is a list of options to pass to the preprocessor/compiler.
# AUXLIBS is a list of options to pass to the linker.
#
CCARGS=		# empty
AUXLIBS=	# empty
FIX_RPATH+=	AUXLIBS

CCARGS+=	-DDEF_CONFIG_DIR=\"${PKG_SYSCONFDIR}\"
CCARGS+=	-DDEF_QUEUE_DIR=\"${POSTFIX_QUEUE_DIR}\"
CCARGS+=	-DDEF_COMMAND_DIR=\"${PREFIX}/sbin\"
CCARGS+=	-DDEF_DAEMON_DIR=\"${LIBEXECDIR}\"
CCARGS+=	-DDEF_SENDMAIL_PATH=\"${PREFIX}/sbin/sendmail\"
CCARGS+=	-DDEF_MAILQ_PATH=\"${PREFIX}/bin/mailq\"
CCARGS+=	-DDEF_NEWALIAS_PATH=\"${PREFIX}/bin/newaliases\"

# Makefile.options appends to CCARGS and AUXLIBS the options needed to
# build Postfix with support for various add-on modules.  It also defines
# _POSTFIX_OPTIONS, which is POSTFIX_OPTIONS filtered to only contain
# supported modules.
#
.include "Makefile.options"

PKG_SYSCONFSUBDIR=	postfix
LIBEXECDIR=		${PREFIX}/libexec/${PKGBASE}
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EXAMPLEDIR=		${PREFIX}/share/examples/${PKGBASE}

FILES_SUBST+=		EXAMPLEDIR=${EXAMPLEDIR}
MESSAGE_SUBST+=		EXAMPLEDIR=${EXAMPLEDIR}

MESSAGE_SRC+=		${PKGDIR}/MESSAGE
.if exists(${PKGDIR}/MESSAGE.${OPSYS})
MESSAGE_SRC+=		${PKGDIR}/MESSAGE.${OPSYS}
.endif
PLIST_SRC+=		${PKGDIR}/PLIST

ALL_TARGET=		# empty
MAKE_ENV=		CC="${CC}" OPT="${CFLAGS}"
MAKE_ENV+=		AUXLIBS="${AUXLIBS}" CCARGS="${CCARGS}"

USE_PKGINSTALL=		yes
RCD_SCRIPTS=		postfix
OWN_DIRS+=		${POSTFIX_QUEUE_DIR}
MAKE_DIRS+=		${PKG_SYSCONFDIR}

PKG_GROUPS?=		postfix maildrop
PKG_USERS?=		postfix:postfix::Postfix\\ User:${POSTFIX_QUEUE_DIR}

CONF_FILES=		${EXAMPLEDIR}/main.cf ${PKG_SYSCONFDIR}/main.cf
CONF_FILES+=		${EXAMPLEDIR}/master.cf ${PKG_SYSCONFDIR}/master.cf
.if !empty(_POSTFIX_OPTIONS:Msasl)
MAKE_DIRS+=		${SASLLIBDIR}
CONF_FILES+=		${EXAMPLEDIR}/smtpd.conf ${SASLLIBDIR}/smtpd.conf
.endif
CONF_FILES_PERMS=	# empty
.for confscr in post-install postfix-files postfix-script
CONF_FILES_PERMS+=	${EXAMPLEDIR}/${confscr} ${PKG_SYSCONFDIR}/${confscr} \
			${ROOT_USER} ${ROOT_GROUP} 755
.endfor
.undef confscr

POSTFIX_CONF_FILES=	conf/main.cf src/util/sys_defs.h		\
			src/global/mail_params.h postfix-install

pre-configure:
	@for i in ${POSTFIX_CONF_FILES}; do				\
		${CP} ${WRKSRC}/$${i} ${WRKSRC}/$${i}.dist;		\
		${SED} ${FILES_SUBST_SED} ${WRKSRC}/$${i}.dist		\
			> ${WRKSRC}/$${i};				\
	done

do-configure:
	cd ${WRKSRC} &&							\
	${SETENV} ${MAKE_ENV} ${MAKE} -f Makefile.init makefiles	\
		'CCARGS=${CCARGS}' 'AUXLIBS=${AUXLIBS}'

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/mailer.conf		\
		> ${WRKDIR}/mailer.conf
.if !empty(_POSTFIX_OPTIONS:Msasl)
	${ECHO} "pwcheck_method: ${PWCHECK_METHOD}" > ${WRKDIR}/smtpd.conf
.endif

do-install:
	${INSTALL_DATA_DIR} ${LIBEXECDIR}
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	-${RM} -f ${WRKSRC}/conf/*.orig
.if !empty(_POSTFIX_OPTIONS:Msasl)
	${INSTALL_DATA} ${WRKDIR}/smtpd.conf ${EXAMPLEDIR}
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/conf/post-install ${EXAMPLEDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/conf/postfix-files ${EXAMPLEDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/conf/postfix-script ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/main.cf ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/master.cf ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKDIR}/mailer.conf ${EXAMPLEDIR}/mailer.conf
	cd ${WRKSRC} && ${SETENV} config_directory="${EXAMPLEDIR}"	\
		${SH} postfix-install -non-interactive

.include "../../mk/bsd.pkg.mk"
