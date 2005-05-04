# $NetBSD: Makefile,v 1.162 2005/05/04 05:20:40 martti Exp $

DISTNAME=	postfix-2.2.3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.porcupine.org/mirrors/postfix-release/official/

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.postfix.org/
COMMENT=	Postfix SMTP server and tools

DIST_SUBDIR=	postfix

CONFLICTS+=	sendmail-[0-9]* fastforward>=0.51nb2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

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

# Set some default paths to override ${WRKSRC}/src/global/mail_params.h.
CCARGS+=	-DDEF_QUEUE_DIR=\"${POSTFIX_QUEUE_DIR}\"
CCARGS+=	-DDEF_DAEMON_DIR=\"${LIBEXECDIR}\"
CCARGS+=	-DDEF_COMMAND_DIR=\"${PREFIX}/sbin\"
CCARGS+=	-DDEF_CONFIG_DIR=\"${PKG_SYSCONFDIR}\"
CCARGS+=	-DDEF_SENDMAIL_PATH=\"${PREFIX}/sbin/sendmail\"
CCARGS+=	-DDEF_MAILQ_PATH=\"${PREFIX}/bin/mailq\"
CCARGS+=	-DDEF_NEWALIAS_PATH=\"${PREFIX}/bin/newaliases\"
CCARGS+=	-DDEF_MANPAGE_DIR=\"${PREFIX}/man\"
CCARGS+=	-DDEF_SAMPLE_DIR=\"${EXAMPLEDIR}\"
CCARGS+=	-DDEF_README_DIR=\"${DOCDIR}\"

# Override those same default paths in the installed example main.cf.
SUBST_CLASSES+=		postfix
SUBST_STAGE.postfix=	post-configure
SUBST_FILES.postfix=	conf/main.cf src/global/mail_params.h
SUBST_SED.postfix=	\
	-e "s|^\(queue_directory\) =.*|\1 = ${POSTFIX_QUEUE_DIR}|"	\
	-e "s|^\(command_directory\) =.*|\1 = ${PREFIX}/sbin|"		\
	-e "s|^\(daemon_directory\) =.*|\1 = ${LIBEXECDIR}|"		\
	-e "s|^\(sendmail_path\) =.*|\1 = ${PREFIX}/sbin/sendmail|"	\
	-e "s|^\(newaliases_path\) =.*|\1 = ${PREFIX}/bin/newaliases|"	\
	-e "s|^\(mailq_path\) =.*|\1 = ${PREFIX}/bin/mailq|"		\
	-e "s|^\(setgid_group\) =.*|\1 = maildrop|"			\
	-e "s|^\(manpage_directory\) =.*|\1 = ${PREFIX}/man|"		\
	-e "s|^\(sample_directory\) =.*|\1 = ${EXAMPLEDIR}|"		\
	-e "s|^\(readme_directory\) =.*|\1 = ${DOCDIR}|"		\
	-e "/^\#define DEF_SGID_GROUP[ 	]/s,postdrop,maildrop,g"

# options.mk appends to CCARGS and AUXLIBS the options needed to build
# Postfix with support for various add-on modules.
#
.include "options.mk"

PKG_SYSCONFSUBDIR=	postfix
LIBEXECDIR=		${PREFIX}/libexec/postfix
DOCDIR=			${PREFIX}/share/doc/postfix
EXAMPLEDIR=		${PREFIX}/share/examples/postfix

FILES_SUBST+=		EXAMPLEDIR=${EXAMPLEDIR}
MESSAGE_SUBST+=		EXAMPLEDIR=${EXAMPLEDIR}
MESSAGE_SUBST+=		DOCDIR=${DOCDIR}

MESSAGE_SRC+=		${PKGDIR}/MESSAGE
.if exists(${PKGDIR}/MESSAGE.${OPSYS})
MESSAGE_SRC+=		${PKGDIR}/MESSAGE.${OPSYS}
.endif
PLIST_SRC+=		${PKGDIR}/PLIST

BUILD_TARGET=		# empty
MAKE_ENV=		CC="${CC}" OPT="${CFLAGS}"
MAKE_ENV+=		AUXLIBS="${AUXLIBS}" CCARGS="${CCARGS}"

USE_PKGINSTALL=		yes
RCD_SCRIPTS=		postfix
OWN_DIRS+=		${POSTFIX_QUEUE_DIR}
MAKE_DIRS+=		${PKG_SYSCONFDIR}

PKG_GROUPS?=		postfix maildrop
PKG_USERS?=		postfix:postfix::Postfix\\ User:${POSTFIX_QUEUE_DIR}

CONF_FILES=		# empty
.for _file_ in main.cf master.cf postfix-files
CONF_FILES+=		${EXAMPLEDIR}/${_file_} ${PKG_SYSCONFDIR}/${_file_}
.endfor
CONF_FILES_PERMS=	# empty
.for _file_ in post-install postfix-script
CONF_FILES_PERMS+=	${EXAMPLEDIR}/${_file_} ${PKG_SYSCONFDIR}/${_file_} \
			${ROOT_USER} ${ROOT_GROUP} 755
.endfor
.undef _file_
.if !empty(PKG_OPTIONS:Msasl)
MAKE_DIRS+=		${SASLLIBDIR}
CONF_FILES+=		${EXAMPLEDIR}/smtpd.conf ${SASLLIBDIR}/smtpd.conf
.endif

MAKE_ENV+=		DEBUG= # empty

do-configure:
	cd ${WRKSRC} &&							\
	${SETENV} ${MAKE_ENV} ${MAKE} -f Makefile.init makefiles	\
		'CCARGS=${CCARGS}' 'AUXLIBS=${AUXLIBS}'

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/mailer.conf		\
		> ${WRKDIR}/mailer.conf
.if !empty(PKG_OPTIONS:Msasl)
	${ECHO} "pwcheck_method: ${PWCHECK_METHOD}" > ${WRKDIR}/smtpd.conf
.endif

do-install:
	${INSTALL_DATA_DIR} ${LIBEXECDIR}
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	-${RM} -f ${WRKSRC}/conf/*.orig
.if !empty(PKG_OPTIONS:Msasl)
	${INSTALL_DATA} ${WRKDIR}/smtpd.conf ${EXAMPLEDIR}
.endif
	@for i in ${POSTFIX_EXAMPLE_FILES}; do				\
		${INSTALL_DATA} ${WRKSRC}/conf/$$i ${EXAMPLEDIR}/$$i;	\
	done
	${INSTALL_SCRIPT} ${WRKSRC}/conf/post-install ${EXAMPLEDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/conf/postfix-script ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKDIR}/mailer.conf ${EXAMPLEDIR}/mailer.conf
	cd ${WRKSRC}; ${SH} ./postfix-install -non-interactive		\
		config_directory="${EXAMPLEDIR}"

.include "../../mk/bsd.pkg.mk"
