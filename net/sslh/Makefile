# $NetBSD: Makefile,v 1.13 2018/12/05 21:20:32 wiz Exp $

DISTNAME=	sslh-1.20
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=yrutschle/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	http://www.rutschle.net/tech/sslh.shtml
COMMENT=	Multiplex ssl, ssh, and other connections on the same port
LICENSE=	gnu-gpl-v2

# version.h created too late
MAKE_JOBS_SAFE=	no

USE_TOOLS+=	gmake gzip pod2man
USE_LANGUAGES=	c

MAKE_FLAGS+=	USELIBWRAP=1

EGDIR=		${PREFIX}/share/examples/sslh
DOCDIR=		share/doc/sslh

CONF_FILES=	${EGDIR}/basic.cfg ${PKG_SYSCONFDIR}/sslh.cfg
RCD_SCRIPTS=	sslh

AUTO_MKDIRS=	yes
REPLACE_SH+=	genver.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sslh-fork ${DESTDIR}${PREFIX}/sbin/sslh
	${INSTALL_PROGRAM} ${WRKSRC}/sslh-select ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/sslh.8.gz ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/scripts/*.* ${DESTDIR}${EGDIR}/scripts
	${INSTALL_DATA} ${WRKSRC}/scripts/fail2ban/* ${DESTDIR}${EGDIR}/scripts/fail2ban
	${INSTALL_DATA} ${WRKSRC}/example.cfg ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/basic.cfg ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.MacOSX ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../devel/libconfig/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
