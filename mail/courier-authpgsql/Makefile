# $NetBSD: Makefile,v 1.6 2004/02/21 14:43:16 jlam Exp $

PKGNAME=	courier-authpgsql-${BASE_VERS}
COMMENT=	Courier PostgreSQL authentication module

DEPENDS+=	courier-auth-${BASE_VERS}{,nb*}:../../mail/courier-auth

.include "../courier-auth/Makefile.authdaemond"

USE_PKGINSTALL=		yes
INSTALL_EXTRA_TMPL=	${.CURDIR}/../courier-auth/INSTALL

CONFIGURE_ARGS+=	--with-authpgsql
CONFIGURE_ARGS+=	--with-pgsql-includes=${BUILDLINK_PREFIX.postgresql-lib}/include/postgresql
CONFIGURE_ARGS+=	--with-pgsql-libs=${BUILDLINK_PREFIX.postgresql-lib}/lib

GEN_FILES=		authpgsqlrc
FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}

CONF_FILES_PERMS=	# empty
.for FILE in ${GEN_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${FILE}.dist ${PKG_SYSCONFDIR}/${FILE}	\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor

.include "../../databases/postgresql-lib/buildlink3.mk"

post-build:
	cd ${WRKSRC}/authlib;						\
	${SED}	-e "s,mysql,pgsql,g"					\
		-e "s,MYSQL,PGSQL,g"					\
		-e "s,MySQL,PostgreSQL,g"				\
		README.authmysql.html > README.authpgsql.html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/authlib/authdaemond.pgsql ${AUTHLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/authlib/authpgsqlrc ${EGDIR}/authpgsqlrc.dist
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/courier
	${INSTALL_DATA} ${WRKSRC}/authlib/README.authpgsql.html		\
		${PREFIX}/share/doc/html/courier

.include "../../mk/bsd.pkg.mk"
