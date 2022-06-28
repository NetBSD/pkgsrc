# $NetBSD: Makefile,v 1.25 2022/06/28 11:36:05 wiz Exp $

DISTNAME=	rsnapshot-1.4.3
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	https://rsnapshot.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rsnapshot.org/
COMMENT=	Filesystem snapshot utility
LICENSE=	gnu-gpl-v2

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
	${INSTALL_SCRIPT} ${WRKSRC}/rsnapshot-diff ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rsnapshot-diff.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/rsnapshot.conf.default ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL.md ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
