# $NetBSD: Makefile,v 1.10 2017/08/01 14:59:05 wiz Exp $
#

DISTNAME=	pacpidump
PKGNAME=	acpidump-20020711
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://people.freebsd.org/~takawata/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	${MASTER_SITES}	# Just a directory list. :-)
COMMENT=	Portable ACPI table dumper

USE_TOOLS+=	gmake
BUILD_TARGET=	# null

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

CFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t -Du_int64_t=uint64_t

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/acpidump ${DESTDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/acpidump.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
