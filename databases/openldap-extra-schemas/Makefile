# $NetBSD: Makefile,v 1.1 2022/04/16 02:48:41 khorben Exp $

DISTNAME=	openldap-extra-schemas-4.3
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenMandrivaAssociation/}
GITHUB_TAG=	release-4.3
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenMandrivaAssociation/openldap-extra-schemas
COMMENT=	Extra schemas for OpenLDAP

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
	cd ${WRKSRC} && pax -rw *.ldif *.schema \
		${DESTDIR}${PREFIX}/${EGDIR}/schema
.include "../../mk/bsd.pkg.mk"
