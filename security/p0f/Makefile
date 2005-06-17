# $NetBSD: Makefile,v 1.16 2005/06/17 03:50:32 jlam Exp $
#

DISTNAME=	p0f-2.0.5
CATEGORIES=	security net
MASTER_SITES=	http://lcamtuf.coredump.cx/p0f/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://lcamtuf.coredump.cx/p0f.shtml
COMMENT=	Passive OS fingerprinting tool

WRKSRC=		${WRKDIR}/p0f
USE_PKGINSTALL=	yes

PKG_SYSCONFSUBDIR=     p0f

CONF_FILES=	${PREFIX}/share/examples/p0f/p0f.fp ${PKG_SYSCONFDIR}/p0f.fp
CONF_FILES+=	${PREFIX}/share/examples/p0f/p0fa.fp ${PKG_SYSCONFDIR}/p0fa.fp
CONF_FILES+=	${PREFIX}/share/examples/p0f/p0fr.fp ${PKG_SYSCONFDIR}/p0fr.fp

SUBST_CLASSES=		paths
SUBST_STAGE.paths=	pre-build
SUBST_FILES.paths=	config.h p0f.1
SUBST_SED.paths=	-e "s|/etc/p0f|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.paths=	"Fixing paths."

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/p0f ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/README ${PREFIX}/share/doc/p0f.README
	${INSTALL_DATA} ${WRKSRC}/p0frep ${PREFIX}/share/doc/p0frep
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/p0f
	${INSTALL_DATA} ${WRKSRC}/p0f.fp ${PREFIX}/share/examples/p0f
	${INSTALL_DATA} ${WRKSRC}/p0fa.fp ${PREFIX}/share/examples/p0f
	${INSTALL_DATA} ${WRKSRC}/p0fr.fp ${PREFIX}/share/examples/p0f
	${INSTALL_MAN} ${WRKSRC}/p0f.1 ${PREFIX}/man/man1

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
