# $NetBSD: Makefile,v 1.7 2004/04/25 04:55:22 snj Exp $
#

DISTNAME=		otpCalc-0.96
PKGREVISION=		2
CATEGORIES=		x11 security
MASTER_SITES=		http://original.killa.net/infosec/otpCalc/

MAINTAINER=		mike@ethmoid.org
HOMEPAGE=		http://original.killa.net/infosec/otpCalc/
COMMENT=		OTP and S/Key calculator for X

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES

ALL_TARGET=		otpCalc otpCalc.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/otpCalc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/otpCalc.1 ${PREFIX}/man/man1

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
