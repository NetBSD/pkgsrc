# $NetBSD: Makefile,v 1.14 2004/10/03 00:13:13 tv Exp $
#

DISTNAME=		bitlbee-0.90a
PKGREVISION=	1
CATEGORIES=		chat
MASTER_SITES=		http://get.bitlbee.org/src/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.bitlbee.org/
COMMENT=		IRC to other chat networks gateway

USE_BUILDLINK3=		yes
HAS_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--bindir=${PREFIX}/sbin
CONFIGURE_ARGS+=	--etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--datadir=${DATADIR}
CONFIGURE_ARGS+=	--config=${STATEDIR}
CONFIGURE_ARGS+=	--flood=1

PKG_SYSCONFSUBDIR=	bitlbee
CONF_FILES=		${DATADIR}/motd.txt ${PKG_SYSCONFDIR}/motd.txt
CONF_FILES+=		${EGDIR}/bitlbee.conf ${PKG_SYSCONFDIR}/bitlbee.conf

EGDIR=			${PREFIX}/share/examples/bitlbee
DATADIR=		${PREFIX}/share/bitlbee
DOCDIR=			${PREFIX}/share/doc/bitlbee
STATEDIR=		/var/db/bitlbee

OWN_DIRS_PERMS=		${STATEDIR} bitlbee nobody 700

PKG_USERS=		bitlbee:nobody::Bitlbee\\ user:/var/db/bitlbee

do-install:
	${INSTALL_DATA_DIR} ${DATADIR} ${DOCDIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/bitlbee.conf ${EGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bitlbee ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/help.txt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/motd.txt ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/doc/bitlbee.8 ${PREFIX}/man/man8
.for f in AUTHORS FAQ README TODO
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCDIR}
.endfor
.undef f

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
