# $NetBSD: Makefile,v 1.12 2004/04/25 03:36:51 snj Exp $
#

DISTNAME=	p0f-2.0.3
CATEGORIES=	security net
MASTER_SITES=	http://lcamtuf.coredump.cx/p0f/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://lcamtuf.coredump.cx/p0f.shtml
COMMENT=	Passive OS fingerprinting tool

WRKSRC=		${WRKDIR}/p0f
USE_BUILDLINK3=	yes
USE_PKGINSTALL=	yes

CONF_FILES=	${PREFIX}/share/examples/p0f/p0f.fp ${PKG_SYSCONFDIR}/p0f.fp

DIST_SUBDIR=	${PKGNAME}

PKG_SYSCONFSUBDIR=     p0f

CONF_FILES=    ${PREFIX}/share/examples/p0f/p0f.fp ${PKG_SYSCONFDIR}/p0f.fp
CONF_FILES+=   ${PREFIX}/share/examples/p0f/p0fa.fp ${PKG_SYSCONFDIR}/p0fa.fp
CONF_FILES+=   ${PREFIX}/share/examples/p0f/p0fr.fp ${PKG_SYSCONFDIR}/p0fr.fp

pre-build:
	@${SED} -e 's#@PKG_SYSCONFDIR@#${PKG_SYSCONFDIR}#g' \
		< ${WRKSRC}/config.h > ${WRKSRC}/config.h.new
	@${SED} -e 's#@PKG_SYSCONFDIR@#${PKG_SYSCONFDIR}#g' \
		< ${WRKSRC}/p0f.1 > ${WRKSRC}/p0f.1.new
	${CP} ${WRKSRC}/config.h.new ${WRKSRC}/config.h
	${CP} ${WRKSRC}/p0f.1.new ${WRKSRC}/p0f.1

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
