# $NetBSD: Makefile,v 1.1.1.1 2000/10/25 19:34:29 tsarna Exp $

DISTNAME=	python-ldap-1.10alpha3-src
PKGNAME=	py-ldap-1.10a3
CATEGORIES=	databases
MASTER_SITES=	http://download.sourceforge.net/python-ldap/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/python-ldap/

DEPENDS+=	python>=2.0:../../lang/python \
		openldap>=1.2.11:../../databases/openldap

WRKSRC=		${WRKDIR}/python-ldap-1.10alpha3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}
MODPATH=	

PLIST_SRC=      ${WRKDIR}/.PLIST_SRC

post-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} lib/python2.0/site-packages/python-ldap \
	 -type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d lib/python2.0/site-packages/python-ldap \
	 -type d -print | ${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
