# $NetBSD: Makefile,v 1.18 2005/02/07 11:35:42 jlam Exp $

PKGNAME=	courier-auth-${BASE_VERS}
PKGREVISION=	1
CATEGORIES=	security
COMMENT=	authentication modules for Courier mail packages

CONFLICTS=	courier-imap<=1.4.0
CONFLICTS+=	courier-imap-ldap-[0-9]*

USE_PERL5=		yes
REPLACE_PERL=		sysconftool

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

PKG_OPTION_VAR=		PKG_OPTIONS.courier-auth

.include "../courier-auth/Makefile.authdaemond"

WRKSRC_FILES+=		imap/system-auth.authpam

INSTALL_DIRS=		${WRKSRC}/liblog ${WRKSRC}/makedat		\
			${WRKSRC}/userdb ${WRKSRC}/authlib

GEN_FILES=		authdaemonrc
FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}

OWN_DIRS_PERMS=		${AUTHDAEMONVAR} ${ROOT_USER} ${ROOT_GROUP} 700
CONF_FILES_PERMS=	# empty
.for FILE in ${GEN_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${FILE}.dist ${PKG_SYSCONFDIR}/${FILE}	\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor
RCD_SCRIPTS=		authdaemond

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/authlib/README.authdebug.html ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/authlib/authdaemonrc			\
		${EGDIR}/authdaemonrc.dist
	${INSTALL_DATA} ${WRKSRC}/imap/system-auth.authpam ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/sysconftool ${SYSCONFTOOL}

.include "../../mk/bsd.pkg.mk"
