# $NetBSD: Makefile,v 1.1.1.1 2002/01/27 22:39:14 jlam Exp $

PKGNAME=	courier-authmysql-${BASE_VERS}
PKGREVISION?=	# empty
COMMENT=	Courier MySQL authentication module

USE_BUILDLINK_ONLY=	yes

.include "../../mail/courier-auth/Makefile.authdaemond"

CONFIGURE_ARGS+=	--with-authmysql
LDFLAGS+=		-Wl,-R${BUILDLINK_PREFIX.mysql-client}/lib/mysql

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

.include "../../databases/mysql-client/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
