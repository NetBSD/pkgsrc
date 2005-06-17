# $NetBSD: Makefile,v 1.4 2005/06/17 03:50:33 jlam Exp $
#

DISTNAME=	pacpidump
PKGNAME=	acpidump-20020711
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freebsd.org/~takawata/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	${MASTER_SITES}	# Just a directory list. :-)
COMMENT=	Portable ACPI table dumper

USE_TOOLS+=	gmake
BUILD_TARGET=	# null

INSTALLATION_DIRS=	bin man/man8

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/acpidump ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/acpidump.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
