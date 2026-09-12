# $NetBSD: Makefile,v 1.32 2026/09/12 15:04:23 wiz Exp $

DISTNAME=	trickle-1.07
CATEGORIES=	net
MASTER_SITES=	https://monkey.org/~marius/trickle/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mariusae/trickle
COMMENT=	Portable lightweight userspace bandwidth shaper
LICENSE=	modified-bsd

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

# Redefines read()
FORTIFY_SUPPORTED=	no

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/trickle
CONF_FILES=	${EGDIR}/trickled.conf ${PKG_SYSCONFDIR}/trickled.conf

RCD_SCRIPTS=		trickled
INSTALLATION_DIRS+=	${EGDIR}

pre-install:
	${INSTALL_DATA} ${FILESDIR}/trickled.conf ${DESTDIR}${EGDIR}

CFLAGS+=	-Wno-implicit-function-declaration
CFLAGS+=	-Wno-incompatible-pointer-types

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
