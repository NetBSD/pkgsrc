# $NetBSD: Makefile,v 1.13 1998/08/20 15:16:46 tsarna Exp $
#

DISTNAME=       cvs-1.9
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	lamj@stat.cmu.edu
HOMEPAGE=	http://www.cyclic.com/cvs/info.html

GNU_CONFIGURE=	yes

CONFLICTS=	cvs-1.9.26 cvs-1.9.27 cvs-1.9.28

.if exists(/usr/lib/libkrb.a)
CONFIGURE_ARGS+=	--with-krb4=/usr --enable-encryption
.endif

MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

INFO_FILES=	cvs.info cvsclient.info

post-install:
	${RM} -f ${PREFIX}/bin/cvs
	${INSTALL_PROGRAM} ${WRKSRC}/src/cvs ${PREFIX}/bin/
	${SH} ${PKGDIR}/INSTALL ${DISTNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
