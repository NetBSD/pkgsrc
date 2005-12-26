# $NetBSD: Makefile,v 1.3 2005/12/26 23:39:32 schmonz Exp $

PKGNAME=	jdk-openjit-${OPENJIT_VERSION}

PKG_FAIL_REASON+=	"Broken on NetBSD/i386 3.0 in pkgsrc-2005Q4"
PKG_FAIL_REASON+=	"Will be removed in pkgsrc-2006Q1 unless fixed"

PKG_JVMS_ACCEPTED= jdk
CLASSDIR=	classes
JRELIB=		lib/${MACHINE_ARCH}/green_threads

.include "../../lang/jdk-openjit/Makefile.common"
