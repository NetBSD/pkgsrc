# $NetBSD: Makefile,v 1.2 2008/10/02 18:03:36 joerg Exp $
#

DISTNAME=		otpCalc-0.96
PKGREVISION=		4
CATEGORIES=		x11 security
MASTER_SITES=		http://original.killa.net/infosec/otpCalc/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://original.killa.net/infosec/otpCalc/
COMMENT=		OTP and S/Key calculator for X

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

BUILD_TARGET=		otpCalc otpCalc.1
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/otpCalc ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/otpCalc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
