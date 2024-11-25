# $NetBSD: Makefile,v 1.33 2024/11/25 13:00:00 nros Exp $

DISTNAME=	repmgr-5.5.0
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=EnterpriseDB/}
GITHUB_PROJECT=	repmgr
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://repmgr.org/
COMMENT=	Replication Manager for PostgreSQL clusters
LICENSE=	gnu-gpl-v3

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

USE_TOOLS+=		flex gmake gsed
GNU_CONFIGURE=		yes
PKG_SYSCONFSUBDIR=	postgresql

BUILD_DEFS+=	PGUSER PGGROUP PGHOME
FILES_SUBST+=	PGUSER=${PGUSER} PGGROUP=${PGGROUP} PGHOME=${PGHOME}

DOCDIR=		share/doc/repmgr
EGDIR=		share/examples/repmgr
SMF_NAME=	postgresql-repmgr

INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

CONF_FILES_PERMS+=	${EGDIR}/repmgr.conf.sample \
			${PKG_SYSCONFDIR}/repmgr.conf \
			${REAL_ROOT_USER} ${PGGROUP} 0640

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/repmgr.conf.sample \
		${DESTDIR}${PREFIX}/${EGDIR}

PLIST_VARS+=	llvm
.include "../../mk/pgsql.buildlink3.mk"
.if !empty(PKG_OPTIONS.postgresql${PGSQL_VERSION}:Mllvm)
PLIST.llvm=	yes
.endif

OPSYSVARS+=	SOEXT
.if ${PGSQL_VERSION} == 16
SOEXT.Darwin=	dylib
.endif
SOEXT.*=	so
PLIST_SUBST+=	SOEXT=${SOEXT}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
