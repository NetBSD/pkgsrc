# $NetBSD: Makefile,v 1.41 2017/01/04 02:14:12 schmonz Exp $

DISTNAME=		ucspi-tcp-0.88
PKGREVISION=		4
CATEGORIES=		sysutils net
MASTER_SITES=		http://cr.yp.to/ucspi-tcp/ ftp://cr.yp.to/ucspi-tcp/
DISTFILES=		${DISTNAME}.tar.gz ${MANPAGES}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/ucspi-tcp.html
COMMENT=		Command-line tools for building TCP client-server applications
LICENSE=		public-domain

MANPAGES=		${DISTNAME}-man-20020317.tar.gz
SITES.${MANPAGES}=	http://smarden.org/pape/djb/manpages/

DJB_RESTRICTED=		no

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-install:
	cd ${WRKDIR}/${PKGNAME_NOREV}-man; for i in 1; do	 	\
		for j in *.$$i; do ${INSTALL_MAN} $$j			\
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man$$i; done	\
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
