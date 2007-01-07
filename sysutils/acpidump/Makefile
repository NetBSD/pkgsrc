# $NetBSD: Makefile,v 1.6 2007/01/07 09:14:11 rillig Exp $
#

DISTNAME=	pacpidump
PKGNAME=	acpidump-20020711
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freebsd.org/~takawata/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	${MASTER_SITES}	# Just a directory list. :-)
COMMENT=	Portable ACPI table dumper

USE_TOOLS+=	gmake
BUILD_TARGET=	# null

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/acpidump ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/acpidump.8 ${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
