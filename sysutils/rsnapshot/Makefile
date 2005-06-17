# $NetBSD: Makefile,v 1.3 2005/06/17 03:50:35 jlam Exp $
#

DISTNAME=	rsnapshot-1.1.6
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.rsnapshot.org/downloads/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.rsnapshot.org/
COMMENT=	Filesystem snapshot utility

DEPENDS+=	rsync>=2.3.1:../../net/rsync
DEPENDS+=	p5-Lchown>=0.07:../../sysutils/p5-Lchown

GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_PKGINSTALL=	yes

.include "../../mk/bsd.prefs.mk"

EGDIR=		${PREFIX}/share/examples/${PKGBASE}

CONF_FILES+=	${EGDIR}/rsnapshot.conf.default \
		${PKG_SYSCONFDIR}/rsnapshot.conf

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-perl=${PERL5}
CONFIGURE_ARGS+=	--with-rsync=${LOCALBASE}/bin/rsync

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rsnapshot ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rsnapshot.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/rsnapshot.conf.default ${EGDIR}

.include "../../mk/bsd.pkg.mk"
