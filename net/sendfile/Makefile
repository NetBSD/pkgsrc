# $NetBSD: Makefile,v 1.13 2003/07/17 22:51:50 grant Exp $
#

DISTNAME=	sendfile-20010216
PKGNAME=	sendfile-2.1.0.2
PKGREVISION=	1
WRKSRC=		${WRKDIR}/sendfile-2.1a
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.belwue.de/pub/unix/sendfile/current/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.belwue.de/aktivitaeten/projekte/saft/
COMMENT=	Implementation of the Simple asynchronous file transfer protocol

USE_BUILDLINK2=	yes
USE_PKGINSTALL=	yes

PKG_SYSCONFSUBDIR=	sendfile
EGDIR=		${PREFIX}/share/examples/sendfile
CONF_FILES=	${EGDIR}/sendfile.cf ${PKG_SYSCONFDIR}/sendfile.cf
CONF_FILES+=	${EGDIR}/sendfile.deny ${PKG_SYSCONFDIR}/sendfile.deny

pre-configure:
	cd ${WRKSRC} && \
	${SED}  -e 's,@PREFIX@,${PREFIX},g' \
		-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g' \
		< makeconfig > makeconfig.new; \
	${MV} makeconfig.new makeconfig; \
	${CHMOD} +x makeconfig

post-configure:
	cd ${WRKSRC} && ${MAKE} config

.include "../../mk/bsd.pkg.mk"
