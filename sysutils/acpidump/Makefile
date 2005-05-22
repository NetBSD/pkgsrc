# $NetBSD: Makefile,v 1.3 2005/05/22 20:08:31 jlam Exp $
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

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/acpidump ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/acpidump.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
