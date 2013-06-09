# $NetBSD: Makefile,v 1.5 2013/06/09 08:52:27 ryoon Exp $
#

DISTNAME=		otpCalc-0.97
CATEGORIES=		x11 security
MASTER_SITES=		http://www.killa.net/infosec/otpCalc/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.killa.net/infosec/otpCalc/
COMMENT=		OTP and S/Key calculator for X

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

BUILD_TARGET=		otpCalc otpCalc.1

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
