# New ports collection makefile for:	cvs
# Version required:     1.9
# Date created:		15 November 1997
# Whom:			lamj@stat.cmu.edu
#
# $NetBSD: Makefile,v 1.5 1998/01/24 03:59:20 hubertf Exp $
#

DISTNAME=       cvs-1.9
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	lamj@stat.cmu.edu

BUILD_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
RUN_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo

GNU_CONFIGURE=	yes

.if exists(/usr/lib/libkrb.a)
CONFIGURE_ARGS+=	--with-krb4=/usr --enable-encryption
.endif

MAN1=		cvs.1
MAN5=		cvs.5
MAN8=		cvsbug.8

post-install:
	strip ${PREFIX}/bin/cvs
	install-info --info-dir=${PREFIX}/info ${PREFIX}/info/cvs.info
	install-info --info-dir=${PREFIX}/info ${PREFIX}/info/cvsclient.info
	${SH} ${PKGDIR}/INSTALL ${DISTNAME} POST-INSTALL

.include <bsd.port.mk>
