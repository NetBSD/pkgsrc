# $NetBSD: Makefile,v 1.2 2002/07/27 22:17:45 jschauma Exp $

# MASTER_SITES is very special, and must end in "=":
DISTNAME=	j2re-1_4_0-linux-i386
PKGNAME=	sun-jre14-0
PKGREVISION=	1
MASTER_SITES=	http://java.sun.com/Download4?config-file=j2re-1_4_0.config&platform=linux-i386&protocol=HTTP+download&download-name=

COMMENT=	Sun's Java(tm) Runtime Environment 1.4.0

WRKSRC=		${WRKDIR}/j2re1.4.0

.include "../../lang/sun-jre14/Makefile.common"

.if ${OPSYS} != "Linux"
DEPENDS+=	suse_compat-[0-9]*:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=	suse_x11-[0-9]*:../../emulators/${SUSE_DIR_PREFIX}_x11
.endif

.include "../../emulators/suse_linux/Makefile.application"

# These need to be after bsd.pkg.mk 
PREFIX:=	${JDK_HOME}
