# $NetBSD: Makefile,v 1.4 2013/12/10 14:01:49 jperkin Exp $
#

DISTNAME=		modcap.c
PKGNAME=		modcap-0.0.5
PKGREVISION=		1
CATEGORIES=		net security
MASTER_SITES=		http://www.emcy.it/Linux/files/
EXTRACT_SUFX=		# empty

MAINTAINER=		agc@NetBSD.org
COMMENT=		Command line utility to modify pcap capture files
LICENSE=		gnu-gpl-v2

AUTO_MKDIRS=		yes

WRKSRC=			${WRKDIR}

LDFLAGS.SunOS+=		-lsocket -lnsl

do-build:
	cd ${WRKSRC} && ${CC} -I${PREFIX}/include modcap.c -lm -lpcap ${LDFLAGS} -o modcap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/modcap ${DESTDIR}${PREFIX}/bin/

.include "../../net/libpcap/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
