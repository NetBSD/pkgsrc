# $NetBSD: Makefile,v 1.10 2003/07/21 16:56:43 martti Exp $

PKGNAME=	courier-auth-${BASE_VERS}
PKGREVISION?=	1
CATEGORIES=	security
COMMENT=	Authentication modules for Courier mail packages

CONFLICTS=	courier-imap<=1.4.0
CONFLICTS+=	courier-imap-ldap-*

USE_PERL5=		yes
USE_PKGINSTALL=		yes
REPLACE_PERL=		sysconftool

.include "../../mail/courier-auth/Makefile.authdaemond"

.if defined(_STRIPFLAG_INSTALL) && !empty(_STRIPFLAG_INSTALL:M-s)
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

FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/sysconftool ${SYSCONFTOOL}
	for file in authdaemonrc.dist; do				\
		${INSTALL_DATA} ${PKG_SYSCONFDIR}/$${file} ${EGDIR};	\
		${RM} -f ${PKG_SYSCONFDIR}/$${file};			\
	done

.include "../../mk/bsd.pkg.mk"
