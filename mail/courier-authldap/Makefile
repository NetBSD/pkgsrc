# $NetBSD: Makefile,v 1.14 2005/02/13 20:44:27 zuntum Exp $

PKGNAME=	courier-authldap-${BASE_VERS}
PKGREVISION=	1
COMMENT=	Courier LDAP authentication module

CONFLICTS=	courier-imap-ldap-[0-9]*

DEPENDS+=	courier-auth-${BASE_VERS}{,nb*}:../../mail/courier-auth

PKG_OPTIONS_VAR=	PKG_OPTIONS.courier-authldap

.include "../courier-auth/Makefile.authdaemond"

USE_PKGINSTALL=		yes
INSTALL_EXTRA_TMPL=	${.CURDIR}/../../mail/courier-auth/INSTALL

CONFIGURE_ARGS+=	--with-authldap

GEN_FILES=		authldaprc
FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}

CONF_FILES_PERMS=	# empty
.for FILE in ${GEN_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${FILE}.dist ${PKG_SYSCONFDIR}/${FILE}	\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor

.include "../../databases/openldap/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM_DIR} ${AUTHLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/authlib/authdaemond.ldap ${AUTHLIBDIR}
	${INSTALL_MAN_DIR} ${DOCDIR}
	${INSTALL_MAN} ${WRKSRC}/authlib/README.ldap ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/authlib/authldap.schema ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/authlib/authldaprc ${EGDIR}/authldaprc.dist

.include "../../mk/bsd.pkg.mk"
