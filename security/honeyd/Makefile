# $NetBSD: Makefile,v 1.6 2005/01/14 21:44:33 adrianp Exp $
#

DISTNAME=	honeyd-1.0
CATEGORIES=	security net
MASTER_SITES=	http://niels.xtdnet.nl/honeyd/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://niels.xtdnet.nl/honeyd/index.php
COMMENT=	Small daemon that creates virtual hosts on a network

.include "../../mk/bsd.prefs.mk"
DEPENDS+=       honeyd-arpd>=0.2:../../security/honeyd-arpd

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_PKGINSTALL=		YES
PKG_SYSCONFSUBDIR=	honeyd
RCD_SCRIPTS=		honeyd
USE_BUILTIN.libevent=	NO

LIBS.Linux+=		-lutil

.include "options.mk"

DIST_CONF_FILES=	nmap.assoc xprobe2.conf nmap.prints \
			config.ethernet pf.os config.sample
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

.for f in ${DIST_CONF_FILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
.undef f

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"

