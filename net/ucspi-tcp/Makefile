# $NetBSD: Makefile,v 1.23 2005/03/23 00:57:20 schmonz Exp $
# FreeBSD Id: ports/sysutils/ucspi-tcp/Makefile,v 1.12 2000/07/10 01:41:24 steve Exp

DISTNAME=		ucspi-tcp-0.88
CATEGORIES=		sysutils net
MASTER_SITES=		http://cr.yp.to/ucspi-tcp/			\
			ftp://cr.yp.to/djbdns/				\
			ftp://ftp.innominate.org/pub/pape/djb/
DISTFILES=		${DISTNAME}.tar.gz				\
			${DISTNAME}-man-20010502.tar.gz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/ucspi-tcp.html
COMMENT=		Command-line tools for building TCP client-server applications

DJB_RESTRICTED=		YES

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		3.0
.endif

INSTALLATION_DIRS=	bin man man/man1

post-install:
	cd ${WRKDIR}/${DISTNAME}-man &&					\
	for i in *.1; do						\
		${INSTALL_MAN} $${i} ${PREFIX}/man/man1;		\
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
