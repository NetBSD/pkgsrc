# $NetBSD: Makefile,v 1.12 2003/07/17 21:28:51 grant Exp $

DISTNAME=	python-ldap-1.10alpha3-src
PKGNAME=	${PYPKGPREFIX}-ldap-1.10a3
WRKSRC=		${WRKDIR}/python-ldap-1.10alpha3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=python-ldap/}

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/python-ldap/
COMMENT=	LDAP client API for Python

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}
CONFIGURE_ARGS+=--with-python=${PYTHONBIN}
USE_BUILDLINK2=	yes

PLIST_SRC=      ${WRKDIR}/.PLIST_SRC

PY_PATCHPLIST=	yes

post-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} ${PYSITELIB}/python-ldap \
	 -type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d ${PYSITELIB}/python-ldap \
	 -type d -print | ${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../databases/openldap1/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
