# $NetBSD: Makefile,v 1.5 2002/11/26 21:46:11 cjep Exp $

DISTNAME=	nmap-3.00
PKGNAME=	nmapfe-0.9.5
CATEGORIES=	net security
MASTER_SITES=	http://codebox.net/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=     reinoud@ibbnet.org,hubertf@netbsd.org
HOMEPAGE=	http://www.insecure.org/nmap/index.html
COMMENT=	graphical front end to the nmap port scanner

DEPENDS+=	nmap-[23].*:../../net/nmap
DEPENDS+=	gtk+-1.2.*:../../x11/gtk

HAS_CONFIGURE=	Yes
CONFIGURE_ENV+= INSTALL=${INSTALL}
CONFIGURE_ARGS+=--prefix=${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=      CPPFLAGS=""
.endif

do-build:
	cd ${WRKSRC}/nbase ; ${SETENV} ${BUILD_ENV} ${MAKE}
	cd ${WRKSRC}/nmapfe ; ${SETENV} ${BUILD_ENV} ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nmapfe/nmapfe ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/nmapfe.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
