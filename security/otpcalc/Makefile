# $NetBSD: Makefile,v 1.2 2002/11/15 00:15:02 jlam Exp $
#

DISTNAME=		otpCalc-0.96
CATEGORIES=		x11 security
MASTER_SITES=		http://original.killa.net/infosec/otpCalc/

MAINTAINER=		mike@ethmoid.org
HOMEPAGE=		http://original.killa.net/infosec/otpCalc/
COMMENT=		OTP and S/Key calculator for X

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_BUILDLINK2=		YES

ALL_TARGET=		otpCalc otpCalc.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/otpCalc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/otpCalc.1 ${PREFIX}/man/man1

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
