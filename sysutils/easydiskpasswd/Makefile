# $NetBSD: Makefile,v 1.7 2005/12/26 23:39:33 schmonz Exp $

DISTNAME=	easydiskpasswd-1.0
CATEGORIES=	sysutils
DISTFILES=	# empty

MAINTAINER=	drochner@NetBSD.org
COMMENT=	Tool to unlock a password protected USB "EasyDisk"

PKG_FAIL_REASON+=	"Broken on NetBSD/i386 3.0 in pkgsrc-2005Q4"
PKG_FAIL_REASON+=	"Will be removed in pkgsrc-2006Q1 unless fixed"

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes

# we depend on SCIOCCOMMAND and the "make" infrastructure
ONLY_FOR_PLATFORM= NetBSD-*-*

do-extract:
	${CP} ${FILESDIR}/easydiskpasswd.c ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
