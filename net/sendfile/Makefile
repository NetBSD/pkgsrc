# $NetBSD: Makefile,v 1.18 2005/12/29 06:22:02 jlam Exp $
#

DISTNAME=	sendfile-20010216
PKGNAME=	sendfile-2.1.0.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.belwue.de/pub/unix/sendfile/current/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.belwue.de/aktivitaeten/projekte/saft/
COMMENT=	Implementation of the Simple asynchronous file transfer protocol

WRKSRC=		${WRKDIR}/sendfile-2.1a

DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

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
