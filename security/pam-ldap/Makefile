# $NetBSD: Makefile,v 1.5 2002/03/15 17:17:45 skrll Exp $
#

DISTNAME=	pam_ldap
PKGNAME=	${DISTNAME:S/_/-/}-${VERSION}
WRKSRC=		${WRKDIR}/${DISTNAME}-${VERSION}
CATEGORIES=	security
MASTER_SITES=	http://www.padl.com/download/ \
		ftp://ftp.padl.com/pub/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.padl.com/pam_ldap.html
COMMENT=	pluggable authentication module for LDAP directories

DEPENDS+=	openldap-[0-9]*:../../databases/openldap
DEPENDS+=	PAM-[0-9]*:../../security/PAM

GNU_CONFIGURE=	YES
CPPFLAGS+=	-I${WRKSRC}
CONFIGURE_ARGS+=--with-ldap-lib=openldap
CONFIGURE_ARGS+=--with-ldap-dir=${PREFIX}
INSTALL_TARGET=	install install-data

VERSION=	77

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pam-ldap
.for doc in COPYING COPYING.LIB INSTALL ChangeLog
	cd ${WRKSRC} && ${INSTALL_DATA} ${doc} ${PREFIX}/share/doc/pam-ldap
.endfor

.include "../../mk/bsd.pkg.mk"
