# $NetBSD: Makefile,v 1.1.1.1 2002/10/04 15:05:05 hubertf Exp $
#

DISTNAME=		otpCalc-0.96
CATEGORIES=		x11 security
MASTER_SITES=		http://original.killa.net/infosec/otpCalc/

MAINTAINER=		mike@ethmoid.org
HOMEPAGE=		http://original.killa.net/infosec/otpCalc/
COMMENT=		OTP and S/Key calculator for X

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_BUILDLINK_ONLY=	YES

ALL_TARGET=		otpCalc otpCalc.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/otpCalc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/otpCalc.1 ${PREFIX}/man/man1

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
