# $NetBSD: Makefile,v 1.10 2010/01/27 19:54:41 joerg Exp $
#

DISTNAME=	rsnapshot-1.2.9
CATEGORIES=	net
MASTER_SITES=	http://www.rsnapshot.org/downloads/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.rsnapshot.org/
COMMENT=	Filesystem snapshot utility

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	rsync>=2.3.1:../../net/rsync
DEPENDS+=	p5-Lchown>=0.07:../../sysutils/p5-Lchown

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl:run

.include "../../mk/bsd.prefs.mk"

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
DOCDIR=		${PREFIX}/share/doc/${PKGBASE}

CONF_FILES+=	${EGDIR}/rsnapshot.conf.default \
		${PKG_SYSCONFDIR}/rsnapshot.conf

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
CONFIGURE_ARGS+=	--with-rsync=${LOCALBASE}/bin/rsync

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${DOCDIR} ${EGDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rsnapshot ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rsnapshot.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/rsnapshot.conf.default ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
