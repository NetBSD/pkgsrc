# $NetBSD: Makefile,v 1.3 2002/10/08 23:15:59 jlam Exp $

PKGNAME=		courier-authmysql-${BASE_VERS}
PKGREVISION?=		# empty
COMMENT=		Courier MySQL authentication module

DEPENDS+=		courier-auth>=${BASE_VERS}:../../mail/courier-auth

.include "../../mail/courier-auth/Makefile.authdaemond"

CONFIGURE_ARGS+=	--with-authmysql
LDFLAGS+=		${BUILDLINK_LDFLAGS.mysql-client}

GEN_FILES=		authmysqlrc
CONF_FILES_PERMS=	# empty
.for FILE in ${GEN_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${FILE}.dist ${PKG_SYSCONFDIR}/${FILE}	\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor

INSTALL_EXTRA_TMPL=	${.CURDIR}/../../mail/courier-auth/INSTALL
FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/authlib/authdaemond.mysql ${AUTHLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/authlib/authmysqlrc ${EGDIR}/authmysqlrc.dist
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/courier
	${INSTALL_DATA} ${WRKSRC}/authlib/README.authmysql.html		\
		${PREFIX}/share/doc/html/courier

.include "../../databases/mysql-client/buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
