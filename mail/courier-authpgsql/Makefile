# $NetBSD: Makefile,v 1.3 2002/10/08 23:16:00 jlam Exp $

PKGNAME=		courier-authpgsql-${BASE_VERS}
PKGREVISION?=		# empty
COMMENT=		Courier PostgreSQL authentication module

DEPENDS+=		courier-auth>=${BASE_VERS}:../../mail/courier-auth

.include "../../mail/courier-auth/Makefile.authdaemond"

CONFIGURE_ARGS+=	--with-authpgsql
CONFIGURE_ARGS+=	--with-pgsql-includes=${BUILDLINK_PREFIX.postgresql-lib}/include/pgsql
CONFIGURE_ARGS+=	--with-pgsql-libs=${BUILDLINK_PREFIX.postgresql-lib}/lib

GEN_FILES=		authpgsqlrc
CONF_FILES_PERMS=	# empty
.for FILE in ${GEN_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${FILE}.dist ${PKG_SYSCONFDIR}/${FILE}	\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor

INSTALL_EXTRA_TMPL=	${.CURDIR}/../../mail/courier-auth/INSTALL
FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}

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

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
