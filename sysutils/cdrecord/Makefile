# New ports collection makefile for:    cdrecord
# Version required:     1.5
# Date created:         2 November 1997
# Whom:                 jmz
#
# $NetBSD: Makefile,v 1.6 1998/02/10 08:07:21 hubertf Exp $
# FreeBSD Id: Makefile,v 1.2 1997/11/05 23:55:31 asami Exp
#

DISTNAME=	cdrecord-1.5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/cdrecord/

MAINTAINER=	jmz@FreeBSD.org

RUN_DEPENDS=	mkisofs:${PORTSDIR}/sysutils/mkisofs

MAN1=		cdrecord.1
USE_GMAKE=	yes

post-configure:
	cd ${WRKSRC}/RULES ; [ -f netbsd-cc.rul ] || mv i386-netbsd-cc.rul netbsd-cc.rul
	cd ${WRKSRC}/RULES ; [ -f netbsd-gcc.rul ] || mv i386-netbsd-gcc.rul netbsd-gcc.rul
	cd ${WRKSRC}/RULES ; ln -sf netbsd-gcc.rul ${ARCH}-netbsd-gcc.rul
	cd ${WRKSRC}/RULES ; ln -sf netbsd-cc.rul ${ARCH}-netbsd-cc.rul

do-build:
	@cd ${WRKSRC}/lib && ../Gmake PREFIX=${PREFIX}
	@cd ${WRKSRC}/cdrecord && ../Gmake PREFIX=${PREFIX}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cdrecord/OBJ/${MACHINE_ARCH}-netbsd-cc/cdrecord \
	 ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/cdrecord/cdrecord.1 ${PREFIX}/man/man1
#	@cd /dev && ln -sf /dev/rworm0.ctl sgx

.include <bsd.port.mk>
