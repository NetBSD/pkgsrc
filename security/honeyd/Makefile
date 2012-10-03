# $NetBSD: Makefile,v 1.40.2.1 2012/10/03 12:09:19 spz Exp $
#

DISTNAME=	honeyd-1.5b
PKGREVISION=	22
CATEGORIES=	security net
MASTER_SITES=	http://www.citi.umich.edu/u/provos/honeyd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.honeyd.org/
COMMENT=	Small daemon that creates virtual hosts on a network
LICENSE=	gnu-gpl-v2 # or later

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	honeyd-arpd>=0.2:../../security/honeyd-arpd

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PKG_SYSCONFSUBDIR=	honeyd
RCD_SCRIPTS=		honeyd

LIBS.Linux+=		-lutil

.include "options.mk"

DIST_CONF_FILES=	nmap.assoc xprobe2.conf nmap.prints \
			config.ethernet pf.os config.sample
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

.for f in ${DIST_CONF_FILES}
CONF_FILES+=		${EGDIR:Q}/${f:Q} ${PKG_SYSCONFDIR:Q}/${f:Q}
.endfor

BUILDLINK_API_DEPENDS.libevent+=	libevent>=1.0
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libdnsres/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"

INSTALLATION_DIRS+=	share/examples/honeyd ${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC:Q}/README ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
