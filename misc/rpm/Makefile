# Makefile for:		rpm
# Version required:	2.4.12
#
# $NetBSD: Makefile,v 1.8 1998/03/20 05:54:42 mycroft Exp $
#

DISTNAME=	rpm-2.4.12
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.redhat.com/pub/redhat/code/rpm/ \
		ftp://ftp.gwdg.de/pub/linux/redhat/code/rpm/

MAINTAINER=	mycroft@NetBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=${MACHINE_ARCH}--netbsd
USE_GMAKE=	yes
MAN8=		rpm.8 rpm2cpio.8

pre-install:
	${MKDIR} ${PREFIX}/include/rpm

.include <bsd.port.mk>
