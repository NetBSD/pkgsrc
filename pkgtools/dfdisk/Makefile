# $NetBSD: Makefile,v 1.19 2019/05/23 19:23:12 rillig Exp $
#

PKGNAME=	dfdisk-1.0
CATEGORIES=	pkgtools

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Fetch distfiles from multiple locations
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

EGDIR=		${PREFIX}/share/examples/dfdisk
CONF_FILES=	${EGDIR}/dfdisk.conf ${PKG_SYSCONFDIR}/dfdisk.conf

.include "../../mk/bsd.prefs.mk"

.if exists(${ZOULARISBASE}/bin/ftp)
FILES_SUBST+=	FTP="${ZOULARISBASE}/bin/ftp -p"
.else
FILES_SUBST+=	FTP="/usr/bin/ftp -p"
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${EGDIR}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	dfdisk.sh dfdisk.1 dfdisk.conf
SUBST_VARS.paths=	PREFIX
SUBST_VARS.paths+=	PKG_SYSCONFDIR
SUBST_VARS.paths+=	PKGVERSION
SUBST_VARS.paths+=	PKGBASE
SUBST_VARS.paths+=	FTP
SUBST_VARS.paths+=	SH
SUBST_STAGE.paths=	pre-install

post-extract:
.for f in dfdisk.sh dfdisk.1 dfdisk.conf
	${CP} ${FILESDIR}/${f} ${WRKDIR}/${f}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/dfdisk.sh ${DESTDIR}${PREFIX}/bin/dfdisk
	${INSTALL_DATA} ${WRKDIR}/dfdisk.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/dfdisk.1
	${INSTALL_DATA} ${WRKDIR}/dfdisk.conf ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
