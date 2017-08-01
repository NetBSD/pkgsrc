# $NetBSD: Makefile,v 1.4 2017/08/01 17:08:24 wiz Exp $

DISTNAME=	libpam-google-authenticator-1.0-source
PKGNAME=	${DISTNAME:S/libpam-//:S/-source//}
CATEGORIES=	security
MASTER_SITES=	http://google-authenticator.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	https://github.com/google/google-authenticator
COMMENT=	One-time password generator and PAM module from Google
LICENSE=	apache-2.0

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
