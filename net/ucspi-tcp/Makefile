# $NetBSD: Makefile,v 1.42 2018/06/18 10:50:19 schmonz Exp $

DISTNAME=		ucspi-tcp-0.88
PKGREVISION=		5
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

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	do-configure
SUBST_FILES.etc=	dns_rcrw.c
SUBST_SED.etc=		-e 's|/etc/dnsrewrite|${PKG_SYSCONFBASE}/dnsrewrite|g'
SUBST_MESSAGE.etc=	Fixing prefix.

BUILD_DEFS+=		PKG_SYSCONFBASE

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-install:
	cd ${WRKDIR}/${PKGNAME_NOREV}-man; for i in 1; do	 	\
		for j in *.$$i; do ${INSTALL_MAN} $$j			\
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man$$i; done	\
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
