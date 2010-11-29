# $NetBSD: Makefile,v 1.1.1.1 2010/11/29 07:25:04 agc Exp $
#

DISTNAME=		modcap.c
PKGNAME=		modcap-0.0.5
CATEGORIES=		net security
MASTER_SITES=		http://www.emcy.it/Linux/files/
EXTRACT_SUFX=		# empty

MAINTAINER=		agc@NetBSD.org
COMMENT=		Command line utility to modify pcap capture files
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
AUTO_MKDIRS=		yes

WRKSRC=			${WRKDIR}

do-build:
	cd ${WRKSRC} && ${CC} -I${PREFIX}/include modcap.c -lm -lpcap -o modcap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/modcap ${DESTDIR}${PREFIX}/bin/

.include "../../net/libpcap/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
