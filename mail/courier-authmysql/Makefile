# $NetBSD: Makefile,v 1.7 2004/07/14 21:43:48 jlam Exp $

PKGNAME=	courier-authmysql-${BASE_VERS}
COMMENT=	Courier MySQL authentication module

DEPENDS+=	courier-auth-${BASE_VERS}{,nb*}:../../mail/courier-auth

.include "../courier-auth/Makefile.authdaemond"

USE_PKGINSTALL=		yes
INSTALL_EXTRA_TMPL=	${.CURDIR}/../courier-auth/INSTALL

CONFIGURE_ARGS+=	--with-authmysql

GEN_FILES=		authmysqlrc
FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}

CONF_FILES_PERMS=	# empty
.for FILE in ${GEN_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${FILE}.dist ${PKG_SYSCONFDIR}/${FILE}	\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor

.include "../../databases/mysql-client/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM_DIR} ${AUTHLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/authlib/authdaemond.mysql ${AUTHLIBDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/authlib/authmysqlrc ${EGDIR}/authmysqlrc.dist
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/authlib/README.authmysql.html	${DOCDIR}

.include "../../mk/bsd.pkg.mk"
