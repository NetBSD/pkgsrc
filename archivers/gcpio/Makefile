# New ports collection makefile for:	gcpio
# Version required:     2.4.2
# Date created:		1 March 1998
# Whom:			tv@netbsd.org
#
# $NetBSD: Makefile,v 1.2 1998/03/05 20:09:46 tv Exp $
#

DISTNAME=       cpio-2.4.2
PKGNAME=	gcpio-2.4.2
CATEGORIES=	archivers
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
