# $NetBSD: Makefile,v 1.3 2012/12/20 21:38:46 joerg Exp $

DISTNAME=	mod_authn_otp-${DISTVERS}
PKGNAME=	otptool-${DISTVERS}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://mod-authn-otp.googlecode.com/files/
LICENSE=	apache-2.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mod-authn-otp.googlecode.com/
COMMENT=	One-Time Password command line utility

PKG_APACHE_ACCEPTED=	apache22

USE_LIBTOOL=	yes

.include "../../mk/apache.mk"

DISTVERS=	1.1.4

SBINDIR=	${PREFIX}/sbin

SUBST_CLASSES+= paths
SUBST_FILES.paths=      configure
SUBST_VARS.paths+=      SBINDIR
SUBST_STAGE.paths=      post-patch

GNU_CONFIGURE=yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/otptool ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/otptool.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../www/apache22/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
