# $NetBSD: Makefile,v 1.1.1.1 2002/01/02 22:26:56 jlam Exp $

PKGNAME=	courier-imap-ldap-${BASE_VERS}
PKGREVISION?=	# empty
COMMENT=	Courier IMAP LDAP authentication daemon

DEPENDS+=	courier-imap>=${BASE_VERS}:../../mail/courier-imap

USE_BUILDLINK_ONLY=	yes

.include "../../mail/courier-imap/Makefile.common"

CONFIGURE_ARGS+=	--with-authldap

GEN_FILES=		authldaprc
CONF_FILES_PERMS=	# empty
.for FILE in ${GEN_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${FILE}.dist ${PKG_SYSCONFDIR}/${FILE}	\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor

INSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL
FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/authlib/authdaemond.ldap ${AUTHLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/authlib/authldap.schema ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/authlib/authldaprc ${EGDIR}/authldaprc.dist

.include "../../databases/openldap/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
