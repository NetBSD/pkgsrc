# $NetBSD: Makefile,v 1.38 2012/06/24 09:29:27 sbd Exp $

DISTNAME=		ucspi-tcp-0.88
PKGREVISION=		3
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

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-install:
	cd ${WRKDIR}/${PKGNAME_NOREV}-man; for i in 1; do	 	\
		for j in *.$$i; do ${INSTALL_MAN} $$j			\
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man$$i; done	\
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
