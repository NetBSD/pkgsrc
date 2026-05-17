# $NetBSD: Makefile,v 1.1 2026/05/17 21:17:32 khorben Exp $

DISTNAME=	openldap-mail-schemas-20180701
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=variablenix/}
GITHUB_PROJECT=	ldap-mail-schema
GITHUB_TAG=	1fe6c77604b772b07eb6dca0d26bcb862ae11176

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/variablenix/ldap-mail-schema
COMMENT=	Mail schemas for OpenLDAP
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pax

DEPENDS+=	openldap-server-[0-9]*:../../databases/openldap-server

NO_BUILD=	YES

EGDIR=		share/examples/openldap

INSTALLATION_DIRS+= \
		    ${EGDIR}/schema

.include "../../mk/bsd.prefs.mk"

OPENLDAP_ETCDIR?=	${PKG_SYSCONFDIR}/openldap

CNFS=			${CNFS_SCHEMAS_cmd:sh}
CNFS_SCHEMAS_cmd=	${SED} -ne "/\.ldif$$/p;/\.schema$$/p" ${PKGDIR}/PLIST | ${SED} -e "s|share/examples/openldap/||"
.for file in ${CNFS}
CONF_FILES+=		${EGDIR}/${file} ${OPENLDAP_ETCDIR}/${file}
.endfor

do-install:
	cd ${WRKSRC} && pax -rw *.schema \
		${DESTDIR}${PREFIX}/${EGDIR}/schema

.include "../../mk/bsd.pkg.mk"
