# $NetBSD: Makefile,v 1.216.6.2 2008/09/05 11:55:45 ghen Exp $

DISTNAME=	postfix-2.5.5
#PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.porcupine.org/mirrors/postfix-release/official/
MASTER_SITES+=	http://postfix.it-austria.net/releases/official/
MASTER_SITES+=	http://mirrors.isc.org/pub/postfix/official/
MASTER_SITES+=	http://mirror.postfix.jp/postfix-release/official/
DIST_SUBDIR=	postfix

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.postfix.org/
COMMENT=	Postfix SMTP server and tools
#LICENSE=	postfix-license

CONFLICTS+=	courier-mta-[0-9]* fastforward>=0.51nb2 sendmail-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	perl
CHECK_HEADERS_SKIP+=	src/global/mail_params.h

.include "../../mk/bsd.prefs.mk"

# POSTFIX_QUEUE_DIR is the default queue directory for Postfix.  This is
# merely a default, and may be changed by setting "queue_directory" in
# ${PKG_SYSCONFDIR}/main.cf.
#
POSTFIX_DATA_DIR?=	${VARBASE}/db/postfix
POSTFIX_QUEUE_DIR?=	${VARBASE}/spool/postfix
BUILD_DEFS+=		VARBASE POSTFIX_DATA_DIR POSTFIX_QUEUE_DIR

# CCARGS is a list of options to pass to the preprocessor/compiler.
# AUXLIBS is a list of options to pass to the linker.
#
CCARGS=		-DUSE_SASL_AUTH
AUXLIBS=	${LDFLAGS}

# Set some default paths to override ${WRKSRC}/src/global/mail_params.h.
CCARGS+=	-DDEF_DATA_DIR=\"${POSTFIX_DATA_DIR}\"
CCARGS+=	-DDEF_QUEUE_DIR=\"${POSTFIX_QUEUE_DIR}\"
CCARGS+=	-DDEF_DAEMON_DIR=\"${LIBEXECDIR}\"
CCARGS+=	-DDEF_COMMAND_DIR=\"${PREFIX}/sbin\"
CCARGS+=	-DDEF_CONFIG_DIR=\"${PKG_SYSCONFDIR}\"
CCARGS+=	-DDEF_SENDMAIL_PATH=\"${PREFIX}/sbin/sendmail\"
CCARGS+=	-DDEF_MAILQ_PATH=\"${PREFIX}/bin/mailq\"
CCARGS+=	-DDEF_NEWALIAS_PATH=\"${PREFIX}/bin/newaliases\"
CCARGS+=	-DDEF_MANPAGE_DIR=\"${PREFIX}/${PKGMANDIR}\"
CCARGS+=	-DDEF_SAMPLE_DIR=\"${EXAMPLEDIR}\"
CCARGS+=	-DDEF_README_DIR=\"${DOCDIR}\"

REPLACE_PERL+=	auxiliary/qshape/qshape.pl

# Override those same default paths in the installed example main.cf.
SUBST_CLASSES+=		postfix
SUBST_STAGE.postfix=	post-configure
SUBST_FILES.postfix=	conf/main.cf src/global/mail_params.h
SUBST_SED.postfix=	\
	-e 's|^\(data_directory\) =.*|\1 = ${POSTFIX_DATA_DIR}|'
SUBST_SED.postfix+=	\
	-e 's|^\(queue_directory\) =.*|\1 = ${POSTFIX_QUEUE_DIR}|'
SUBST_SED.postfix+=	\
	-e 's|^\(command_directory\) =.*|\1 = ${PREFIX}/sbin|'
SUBST_SED.postfix+=	\
	-e 's|^\(daemon_directory\) =.*|\1 = ${LIBEXECDIR}|'
SUBST_SED.postfix+=	\
	-e 's|^\(sendmail_path\) =.*|\1 = ${PREFIX}/sbin/sendmail|'
SUBST_SED.postfix+=	\
	-e 's|^\(newaliases_path\) =.*|\1 = ${PREFIX}/bin/newaliases|'
SUBST_SED.postfix+=	\
	-e 's|^\(mailq_path\) =.*|\1 = ${PREFIX}/bin/mailq|'
SUBST_SED.postfix+=	\
	-e 's|^\(setgid_group\) =.*|\1 = maildrop|'
SUBST_SED.postfix+=	\
	-e 's|^\(manpage_directory\) =.*|\1 = ${PREFIX}/${PKGMANDIR}|'
SUBST_SED.postfix+=	\
	-e 's|^\(sample_directory\) =.*|\1 = ${EXAMPLEDIR}|'
SUBST_SED.postfix+=	\
	-e 's|^\(readme_directory\) =.*|\1 = ${DOCDIR}|'
SUBST_SED.postfix+=	\
	-e '/^\#define DEF_SGID_GROUP[ 	]/s,postdrop,maildrop,g'

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
MAKE_ENV+=		CC=${CC:Q} OPT=${CFLAGS:Q}
MAKE_ENV+=		AUXLIBS=${AUXLIBS:Q} CCARGS=${CCARGS:Q}

RCD_SCRIPTS=		postfix
OWN_DIRS+=		${POSTFIX_QUEUE_DIR} ${POSTFIX_QUEUE_DIR}/etc
OWN_DIRS_PERMS+=	${POSTFIX_DATA_DIR} postfix postfix 0700
MAKE_DIRS+=		${PKG_SYSCONFDIR}

PKG_GROUPS?=		postfix maildrop
PKG_USERS?=		postfix:postfix
PKG_GECOS.postfix=	Postfix User
PKG_HOME.postfix=	${POSTFIX_QUEUE_DIR}

CONF_FILES=		# empty
.for i in main.cf master.cf postfix-files
CONF_FILES+=		${EXAMPLEDIR}/${i} ${PKG_SYSCONFDIR}/${i}
.endfor
CONF_FILES_PERMS=	# empty
.for i in post-install postfix-script
CONF_FILES_PERMS+=	${EXAMPLEDIR}/${i} ${PKG_SYSCONFDIR}/${i} \
			${ROOT_USER} ${ROOT_GROUP} 755
.endfor

MAKE_ENV+=		DEBUG= # empty

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/mailer.conf
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_STAGE.paths=	post-patch

post-extract:
	cp ${FILESDIR}/mailer.conf ${WRKDIR}/mailer.conf
	rm -f ${WRKSRC}/auxiliary/MacOSX/Postfix.StartupItem/Postfix

do-configure:
	cd ${WRKSRC} &&							\
	env ${MAKE_ENV} ${MAKE} -f Makefile.init makefiles		\
		'CCARGS=${CCARGS}' 'AUXLIBS=${AUXLIBS}'

post-build:
.if !empty(PKG_OPTIONS:Msasl)
	${ECHO} "pwcheck_method: ${PWCHECK_METHOD}" > ${WRKDIR}/smtpd.conf
.endif

do-install:
	${INSTALL_DATA_DIR} ${LIBEXECDIR}
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	rm -f ${WRKSRC}/conf/*.orig
.if !empty(PKG_OPTIONS:Msasl)
	${INSTALL_DATA} ${WRKDIR}/smtpd.conf ${EXAMPLEDIR}
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/conf/post-install ${EXAMPLEDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/conf/postfix-script ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKDIR}/mailer.conf ${EXAMPLEDIR}/mailer.conf
	cd ${WRKSRC} && sh ./postfix-install -non-interactive		\
		config_directory="${EXAMPLEDIR}"
	${INSTALL_SCRIPT} ${WRKSRC}/auxiliary/qshape/qshape.pl \
		${PREFIX}/sbin/qshape
	${INSTALL_MAN} ${WRKSRC}/man/man1/qshape.1 \
		${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
