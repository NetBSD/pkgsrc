# $NetBSD: Makefile,v 1.1.1.1 2004/04/20 09:14:43 xtraeme Exp $
#

DISTNAME=	honeyd-0.8b
CATEGORIES=	security net
MASTER_SITES=	http://niels.xtdnet.nl/honeyd/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://niels.xtdnet.nl/honeyd/index.php
COMMENT=	Small daemon that creates virtual hosts on a network

DEPENDS+=       honeyd-arpd>=0.2:../../security/honeyd-arpd

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
PKG_SYSCONFSUBDIR=	honeyd
RCD_SCRIPTS=		honeyd

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

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

