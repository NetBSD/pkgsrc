# New ports collection makefile for:	gcpio
# Version required:     2.4.2
# Date created:		1 March 1998
# Whom:			tv@netbsd.org
#
# $NetBSD: Makefile,v 1.1.1.1 1998/03/04 14:51:38 tv Exp $
#

DISTNAME=       cpio-2.4.2
PKGNAME=	gcpio-2.4.2
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

OPSYS!= uname -s
.if (${OPSYS} == "NetBSD")
BUILD_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
.endif

GNU_CONFIGURE=yes
CONFIGURE_ARGS= --program-prefix=g
LDFLAGS=	-lgnumalloc

MAN1=	gcpio.1

post-install:
	install-info --info-dir=${PREFIX}/info ${PREFIX}/info/cpio.info

.include <bsd.port.mk>
