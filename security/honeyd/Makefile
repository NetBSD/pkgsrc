# $NetBSD: Makefile,v 1.87 2024/05/29 16:34:14 adam Exp $
#

DISTNAME=	honeyd-1.5c
PKGREVISION=	14
CATEGORIES=	security net
MASTER_SITES=	https://www.honeyd.org/uploads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.honeyd.org/
COMMENT=	Small daemon that creates virtual hosts on a network
LICENSE=	gnu-gpl-v2 # or later

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
.include "../../mk/readline.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"

INSTALLATION_DIRS+=	share/examples/honeyd ${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC:Q}/README ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
