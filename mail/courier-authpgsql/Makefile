# $NetBSD: Makefile,v 1.12 2005/02/07 11:35:44 jlam Exp $

PKGNAME=	courier-authpgsql-${BASE_VERS}
COMMENT=	Courier PostgreSQL authentication module

DEPENDS+=	courier-auth-${BASE_VERS}{,nb*}:../../mail/courier-auth

PKG_OPTION_VAR=	PKG_OPTIONS.courier-authpgsql

.include "../courier-auth/Makefile.authdaemond"

USE_PKGINSTALL=		yes
INSTALL_EXTRA_TMPL=	${.CURDIR}/../courier-auth/INSTALL

CONFIGURE_ARGS+=	--with-authpgsql
CONFIGURE_ARGS+=	--with-pgsql-includes=${PGSQL_PREFIX}/include/postgresql
CONFIGURE_ARGS+=	--with-pgsql-libs=${PGSQL_PREFIX}/lib

GEN_FILES=		authpgsqlrc
FILES_SUBST+=		GEN_FILES=${GEN_FILES:Q}

CONF_FILES_PERMS=	# empty
.for FILE in ${GEN_FILES}
CONF_FILES_PERMS+=	${EGDIR}/${FILE}.dist ${PKG_SYSCONFDIR}/${FILE}	\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor

.include "../../mk/pgsql.buildlink3.mk"

post-build:
	cd ${WRKSRC}/authlib;						\
	${SED}	-e "s,mysql,pgsql,g"					\
		-e "s,MYSQL,PGSQL,g"					\
		-e "s,MySQL,PostgreSQL,g"				\
		README.authmysql.html > README.authpgsql.html
	for file in README.authpostgres.html; do			\
		${SED}	-e "s,mysql,pgsql,g"				\
			$$file > $$file.new;				\
		${MV} -f $$file.new $$file;				\
	done

do-install:
	${INSTALL_PROGRAM_DIR} ${AUTHLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/authlib/authdaemond.pgsql ${AUTHLIBDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/authlib/authpgsqlrc ${EGDIR}/authpgsqlrc.dist
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/authlib/README.authpgsql.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/authlib/README.authpostgres.html ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
