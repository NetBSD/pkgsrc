# $NetBSD: Makefile,v 1.2 2004/12/03 15:15:09 wiz Exp $
#

DISTNAME=	pacpidump
PKGNAME=	acpidump-20020711
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freebsd.org/~takawata/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	${MASTER_SITES}	# Just a directory list. :-)
COMMENT=	Portable ACPI table dumper

USE_GNU_TOOLS+=	make
BUILD_TARGET=	# null

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/acpidump ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/acpidump.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
