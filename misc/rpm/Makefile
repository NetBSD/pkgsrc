# $NetBSD: Makefile,v 1.3 1997/10/27 01:06:12 hubertf Exp $
# New ports collection makefile for:	rpm
# Version required:	2.4.8
# Date created:		23 January 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# FreeBSD Id: Makefile,v 1.9 1997/09/23 07:07:32 tg Exp
#

DISTNAME=	rpm-2.4.8
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.redhat.com/pub/redhat/code/rpm/ \
		ftp://ftp.gwdg.de/pub/linux/redhat/code/rpm/

MAINTAINER=	tg@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ARCH}--netbsd
USE_GMAKE=	yes
MAN8=		rpm.8 rpm2cpio.8

pre-install:
	${MKDIR} ${PREFIX}/include/rpm

.include <bsd.port.mk>
