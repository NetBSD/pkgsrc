# $NetBSD: Makefile,v 1.13 2004/02/22 02:18:31 jlam Exp $

PKGNAME=	courier-auth-${BASE_VERS}
CATEGORIES=	security
COMMENT=	Authentication modules for Courier mail packages

CONFLICTS=	courier-imap<=1.4.0
CONFLICTS+=	courier-imap-ldap-*

USE_PERL5=		yes
REPLACE_PERL=		sysconftool

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

.include "../courier-auth/Makefile.authdaemond"

WRKSRC_FILES+=		imap/system-auth.authpam

.if defined(_STRIPFLAG_INSTALL) && !empty(_STRIPFLAG_INSTALL:M-s)
INSTALL_TARGET=		install-strip
.endif
INSTALL_DIRS=		${WRKSRC}/makedat ${WRKSRC}/userdb ${WRKSRC}/authlib

GEN_FILES=		authdaemonrc
FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}

OWN_DIRS_PERMS=		/var/authdaemon ${ROOT_USER} ${ROOT_GROUP} 700
CONF_FILES_PERMS=	# empty
.for FILE in ${GEN_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${FILE}.dist ${PKG_SYSCONFDIR}/${FILE}	\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor
RCD_SCRIPTS=		authdaemond

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/authlib/authdaemonrc			\
		${EGDIR}/authdaemonrc.dist
	${INSTALL_DATA} ${WRKSRC}/imap/system-auth.authpam ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/sysconftool ${SYSCONFTOOL}

.include "../../mk/bsd.pkg.mk"
