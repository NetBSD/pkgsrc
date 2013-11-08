# $NetBSD: Makefile,v 1.3 2013/11/08 13:33:55 obache Exp $
#

DISTNAME=	sslh-1.15
CATEGORIES=	net
MASTER_SITES=	http://www.rutschle.net/tech/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rutschle.net/tech/sslh.shtml
COMMENT=	Multiplex ssl and ssh connections on the same port
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake gzip pod2man
USE_LANGUAGES=	c

MAKE_FLAGS+=	USELIBWRAP=1

EGDIR=		${PREFIX}/share/examples/sslh
DOCDIR=		share/doc/sslh

CONF_FILES=	${EGDIR}/basic.cfg ${PKG_SYSCONFDIR}/sslh.cfg
RCD_SCRIPTS=	sslh

AUTO_MKDIRS=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sslh-fork ${DESTDIR}${PREFIX}/sbin/sslh
	${INSTALL_PROGRAM} ${WRKSRC}/sslh-select ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/sslh.8.gz ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/scripts/* ${DESTDIR}${EGDIR}/scripts
	${INSTALL_DATA} ${WRKSRC}/example.cfg ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/basic.cfg ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.MacOSX ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../devel/libconfig/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
