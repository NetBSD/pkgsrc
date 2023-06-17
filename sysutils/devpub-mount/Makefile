# $NetBSD: Makefile,v 1.1 2023/06/17 15:24:05 bacon Exp $

DISTNAME=	devpub-mount-0.1.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/devpub-mount/
COMMENT=	NetBSD devpubd-based automounter
LICENSE=	2-clause-bsd

NO_BUILD=	yes

DATADIR=	${PREFIX}/share/devpub-mount
EGDIR=		${PREFIX}/share/examples/devpub-mount

CONF_FILES=	${EGDIR}/devpub-mount.conf.sample ${PREFIX}/etc/devpub-mount.conf

INSTALLATION_DIRS=	sbin share/examples/devpub-mount share/devpub-mount ${PKGMANDIR}/man8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/devpub-mount ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/devpub-mount.conf \
		${DESTDIR}${EGDIR}/devpub-mount.conf.sample
	${INSTALL_DATA} ${WRKSRC}/03-devpub-mount ${DESTDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/Man/*.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
