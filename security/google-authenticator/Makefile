# $NetBSD: Makefile,v 1.2 2012/08/11 17:09:43 jmmv Exp $

DISTNAME=	libpam-google-authenticator-1.0-source
PKGNAME=	${DISTNAME:S/libpam-//:S/-source//}
CATEGORIES=	security
MASTER_SITES=	http://google-authenticator.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	http://code.google.com/p/google-authenticator/
MAINTAINER=	jmmv@NetBSD.org
COMMENT=	One-time password generator and PAM module from Google

LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir
USE_TOOLS=		gmake

CFLAGS+=	-DNO_STATIC_MODULES
WRKSRC=		${WRKDIR}/${DISTNAME:S/-source//}

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
