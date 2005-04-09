# $NetBSD: Makefile,v 1.26 2005/04/09 22:44:15 schmonz Exp $

DISTNAME=		ucspi-tcp-0.88
PKGREVISION=		1
CATEGORIES=		sysutils net
MASTER_SITES=		http://cr.yp.to/ucspi-tcp/ ftp://cr.yp.to/ucspi-tcp/
DISTFILES=		${DISTNAME}.tar.gz ${MANPAGES}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/ucspi-tcp.html
COMMENT=		Command-line tools for building TCP client-server applications

MANPAGES=		${DISTNAME}-man-20020317.tar.gz
SITES_${MANPAGES}=	http://smarden.org/pape/djb/manpages/

DJB_RESTRICTED=		YES

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		3.0
.endif

INSTALLATION_DIRS=	bin man man/man1

post-install:
	cd ${WRKDIR}/*-man; for i in 1; do		 		\
	for j in *.$$i; do ${INSTALL_MAN} $$j ${PREFIX}/man/man$$i; done \
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
