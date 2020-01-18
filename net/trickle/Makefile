# $NetBSD: Makefile,v 1.29 2020/01/18 21:50:27 jperkin Exp $
#

DISTNAME=	trickle-1.06
PKGREVISION=	16
CATEGORIES=	net
MASTER_SITES=	https://monkey.org/~marius/trickle/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://monkey.org/~marius/trickle/
COMMENT=	Portable lightweight userspace bandwidth shaper

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/trickle
CONF_FILES=	${EGDIR}/trickled.conf ${PKG_SYSCONFDIR}/trickled.conf

RCD_SCRIPTS=		trickled
INSTALLATION_DIRS+=	${EGDIR}

pre-install:
	${INSTALL_DATA} ${FILESDIR}/trickled.conf ${DESTDIR}${EGDIR}

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
