# $NetBSD: Makefile,v 1.21 2008/04/22 18:06:09 tnn Exp $
#

DISTNAME=	honeyd-1.5b
PKGREVISION=	5
CATEGORIES=	security net
MASTER_SITES=	http://www.citi.umich.edu/u/provos/honeyd/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.honeyd.org/
COMMENT=	Small daemon that creates virtual hosts on a network

DEPENDS+=	honeyd-arpd>=0.2:../../security/honeyd-arpd

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
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
CONF_FILES+=		${EGDIR:Q}/${f:Q} ${PKG_SYSCONFDIR:Q}/${f:Q}
.endfor

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libdnsres/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/examples/honeyd

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC:Q}/README ${DOCDIR:Q}

.include "../../mk/bsd.pkg.mk"
