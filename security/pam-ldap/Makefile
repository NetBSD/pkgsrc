# $NetBSD: Makefile,v 1.4 2001/09/27 23:18:40 jlam Exp $
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

post-configure:		# prevent starting of autoconf
.for file in aclocal.m4 Makefile.in Makefile stamp-h.in stamp-h
	cd ${WRKSRC} && ${TOUCH} ${file}
.endfor

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pam-ldap
.for doc in COPYING COPYING.LIB INSTALL ChangeLog
	cd ${WRKSRC} && ${INSTALL_DATA} ${doc} ${PREFIX}/share/doc/pam-ldap
.endfor

.include "../../mk/bsd.pkg.mk"
