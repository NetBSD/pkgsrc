# $NetBSD: Makefile,v 1.4 2002/02/03 13:38:38 jlam Exp $

PKGNAME=	courier-auth-${BASE_VERS}
PKGREVISION?=	1
CATEGORIES=	security
COMMENT=	authentication modules for Courier mail packages

CONFLICTS=	courier-imap<=1.4.0
CONFLICTS+=	courier-imap-ldap-*

USE_BUILDLINK_ONLY=	yes
USE_PERL5=		yes
REPLACE_PERL=		sysconftool

.include "../../mail/courier-auth/Makefile.authdaemond"

.if defined(STRIPFLAG) && !empty(STRIPFLAG:M-s)
INSTALL_TARGET=		install-strip
.endif

GEN_FILES=		authdaemonrc
OWN_DIRS_PERMS=		/var/authdaemon ${ROOT_USER} ${ROOT_GROUP} 700

CONF_FILES_PERMS=	# empty
.for FILE in ${GEN_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${FILE}.dist ${PKG_SYSCONFDIR}/${FILE}	\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor
RCD_SCRIPTS=		authdaemond

DEINSTALL_EXTRA_TMPL=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL
FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}

do-install:
.for DIR in ${WRKSRC_SUBDIRS}
	@cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${INSTALL_TARGET}
.endfor

post-install:
	@for file in ${RCD_SCRIPTS}; do					\
		${SED} ${FILES_SUBST_SED} ${FILESDIR}/$${file}.sh	\
			> ${WRKDIR}/$${file}.sh;			\
		${INSTALL_SCRIPT} ${WRKDIR}/$${file}.sh			\
			${PREFIX}/etc/rc.d/$${file};			\
	done
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/sysconftool ${SYSCONFTOOL}
	for file in authdaemonrc.dist; do				\
		${INSTALL_DATA} ${PKG_SYSCONFDIR}/$${file} ${EGDIR};	\
		${RM} -f ${PKG_SYSCONFDIR}/$${file};			\
	done

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
