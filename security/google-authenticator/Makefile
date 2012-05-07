# $NetBSD: Makefile,v 1.1.1.1 2012/05/07 00:01:48 jmmv Exp $

DISTNAME=	google-authenticator-0.0.20120506
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/jmmv/google-authenticator/

HOMEPAGE=	http://code.google.com/p/google-authenticator/
MAINTAINER=	jmmv@NetBSD.org
COMMENT=	One-time password generator and PAM module from Google

LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir
USE_TOOLS=		gmake

BUILD_TARGET=	google-authenticator pam_google_authenticator.so
CFLAGS+=	-DNO_STATIC_MODULES
WRKSRC=		${WRKDIR}/google-authenticator/libpam

INSTALLATION_DIRS=	bin lib/security share/doc/google-authenticator

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} google-authenticator \
	    ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_LIB} pam_google_authenticator.so \
	    ${DESTDIR}${PREFIX}/lib/security
	cd ${WRKSRC} && ${INSTALL_DATA} README \
	    ${DESTDIR}${PREFIX}/share/doc/google-authenticator

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
