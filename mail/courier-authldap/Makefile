# $NetBSD: Makefile,v 1.3 2002/01/27 23:47:08 jlam Exp $

PKGNAME=		courier-authldap-${BASE_VERS}
PKGREVISION?=		# empty
COMMENT=		Courier LDAP authentication module

CONFLICTS=		courier-imap-ldap-[0-9]*

DEPENDS+=		courier-auth>=${BASE_VERS}:../../mail/courier-auth

USE_BUILDLINK_ONLY=	yes

.include "../../mail/courier-auth/Makefile.authdaemond"

CONFIGURE_ARGS+=	--with-authldap

GEN_FILES=		authldaprc
CONF_FILES_PERMS=	# empty
.for FILE in ${GEN_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${FILE}.dist ${PKG_SYSCONFDIR}/${FILE}	\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor

FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}
INSTALL_EXTRA_TMPL=	${.CURDIR}/../../mail/courier-auth/INSTALL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/authlib/authdaemond.ldap ${AUTHLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/authlib/authldap.schema ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/authlib/authldaprc ${EGDIR}/authldaprc.dist

.include "../../databases/openldap/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
