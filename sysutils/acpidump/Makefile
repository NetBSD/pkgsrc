# $NetBSD: Makefile,v 1.1.1.1 2004/02/29 05:57:44 uebayasi Exp $
#

DISTNAME=	pacpidump
PKGNAME=	acpidump-20020711
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freebsd.org/~takawata/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	${MASTER_SITES}	# Just a directory list. :-)
COMMENT=	Portable ACPI table dumper

USE_GNU_TOOLS+=	make
ALL_TARGET=	# null

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/acpidump ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/acpidump.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
