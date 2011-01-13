# $NetBSD: Makefile,v 1.31 2011/01/13 14:03:21 wiz Exp $
#

DISTNAME=	honeyd-1.5b
PKGREVISION=	13
CATEGORIES=	security net
MASTER_SITES=	http://www.citi.umich.edu/u/provos/honeyd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.honeyd.org/
COMMENT=	Small daemon that creates virtual hosts on a network

PKG_DESTDIR_SUPPORT=	user-destdir

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

INSTALLATION_DIRS+=	share/examples/honeyd ${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC:Q}/README ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
