# $NetBSD: Makefile,v 1.10 2003/01/04 18:16:22 cjep Exp $

DISTNAME=	python-ldap-1.10alpha3-src
PKGNAME=	${PYPKGPREFIX}-ldap-1.10a3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=python-ldap/}

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/python-ldap/
COMMENT=	LDAP client API for Python

WRKSRC=		${WRKDIR}/python-ldap-1.10alpha3
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
