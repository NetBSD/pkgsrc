# New ports collection makefile for:	cvs
# Version required:     1.9
# Date created:		15 November 1997
# Whom:			lamj@stat.cmu.edu
#
# $NetBSD: Makefile,v 1.7 1998/03/25 17:50:15 tv Exp $
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

MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

MAN1=		cvs.1
MAN5=		cvs.5
MAN8=		cvsbug.8

post-install:
	${RM} -f ${PREFIX}/bin/cvs
	${INSTALL_PROGRAM} ${WRKSRC}/src/cvs ${PREFIX}/bin/
	install-info --info-dir=${PREFIX}/info ${PREFIX}/info/cvs.info
	install-info --info-dir=${PREFIX}/info ${PREFIX}/info/cvsclient.info
	${SH} ${PKGDIR}/INSTALL ${DISTNAME} POST-INSTALL

.include <bsd.port.mk>
