# $NetBSD: Makefile,v 1.4 2004/10/03 00:18:09 tv Exp $
#

DISTNAME=	honeyd-0.8b
PKGREVISION=	3
CATEGORIES=	security net
MASTER_SITES=	http://niels.xtdnet.nl/honeyd/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://niels.xtdnet.nl/honeyd/index.php
COMMENT=	Small daemon that creates virtual hosts on a network

DEPENDS+=       honeyd-arpd>=0.2:../../security/honeyd-arpd

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
PKG_SYSCONFSUBDIR=	honeyd
RCD_SCRIPTS=		honeyd

CONFIGURE_ENV+=		_PATH_PYTHON=${PYTHONBIN}
LIBS.Linux+=		-lutil

DIST_CONF_FILES=	nmap.assoc xprobe2.conf nmap.prints \
			config.ethernet pf.os
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

.for f in ${DIST_CONF_FILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
.undef f

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../lang/python/extension.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

