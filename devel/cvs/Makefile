# $NetBSD: Makefile,v 1.9 1998/04/17 09:37:23 agc Exp $
#

DISTNAME=       cvs-1.9
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	lamj@stat.cmu.edu

GNU_CONFIGURE=	yes

.if exists(/usr/lib/libkrb.a)
CONFIGURE_ARGS+=	--with-krb4=/usr --enable-encryption
.endif

MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

MAN1=		cvs.1
MAN5=		cvs.5
MAN8=		cvsbug.8
INFO_FILES=	cvs cvsclient

post-install:
	${RM} -f ${PREFIX}/bin/cvs
	${INSTALL_PROGRAM} ${WRKSRC}/src/cvs ${PREFIX}/bin/
	${SH} ${PKGDIR}/INSTALL ${DISTNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
