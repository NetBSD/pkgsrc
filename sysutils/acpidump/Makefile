# $NetBSD: Makefile,v 1.8 2012/10/23 19:50:50 asau Exp $
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
	@${INSTALL_PROGRAM} ${WRKSRC}/acpidump ${DESTDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/acpidump.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
