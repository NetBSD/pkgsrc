# $NetBSD: Makefile,v 1.6 2003/03/22 04:08:20 salo Exp $
#

DISTNAME=	nmap-3.20
PKGNAME=	nmapfe-0.9.5
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://codebox.net/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=     reinoud@ibbnet.org,hubertf@netbsd.org
HOMEPAGE=	http://www.insecure.org/nmap/index.html
COMMENT=	graphical front end to the nmap port scanner

DEPENDS+=	nmap-[23].*:../../net/nmap
DEPENDS+=	gtk+-1.2.*:../../x11/gtk

GNU_CONFIGURE=	YES

PATCHDIR=	${.CURDIR}/../../net/nmap/patches
DISTINFO_FILE=	${.CURDIR}/../../net/nmap/distinfo

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
