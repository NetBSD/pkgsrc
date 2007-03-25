# $NetBSD: Makefile,v 1.1.1.1 2007/03/25 06:12:29 wiz Exp $
#

DISTNAME=		otpCalc-0.96
PKGREVISION=		4
CATEGORIES=		x11 security
MASTER_SITES=		http://original.killa.net/infosec/otpCalc/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://original.killa.net/infosec/otpCalc/
COMMENT=		OTP and S/Key calculator for X

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

BUILD_TARGET=		otpCalc otpCalc.1
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/otpCalc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/otpCalc.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
