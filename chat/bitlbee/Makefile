# $NetBSD: Makefile,v 1.1.1.1 2003/07/02 09:03:02 jmmv Exp $
#

DISTNAME=		bitlbee-0.80
CATEGORIES=		chat
MASTER_SITES=		http://www.lintux.cx/downloads/

MAINTAINER=		jrp@hispabsd.org
HOMEPAGE=		http://www.lintux.cx/downloads/
COMMENT=		IRC to other chat networks gateway

USE_BUILDLINK2=		yes
HAS_CONFIGURE=		yes
USE_GMAKE=		yes
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--bindir=${PREFIX}/sbin
CONFIGURE_ARGS+=	--etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--datadir=${DATADIR}
CONFIGURE_ARGS+=	--config=${STATEDIR}

PKG_SYSCONFSUBDIR=	bitlbee
CONF_FILES=		${DATADIR}/motd.txt ${PKG_SYSCONFDIR}/motd.txt

DATADIR=		${PREFIX}/share/bitlbee
DOCDIR=			${PREFIX}/share/doc/bitlbee
STATEDIR=		/var/db/bitlbee

OWN_DIRS_PERMS=		${STATEDIR} bitlbee nobody 700

PKG_USERS=		bitlbee:nobody::Bitlbee\\ user:/var/db/bitlbee

do-install:
	${INSTALL_DATA_DIR} ${DATADIR} ${DOCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bitlbee ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/help.txt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/motd.txt ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/doc/bitlbee.8 ${PREFIX}/man/man8
.for f in AUTHORS FAQ README TODO
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCDIR}
.endfor
.undef f

.include "../../devel/glib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
