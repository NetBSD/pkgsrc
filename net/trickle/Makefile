# $NetBSD: Makefile,v 1.10 2005/09/16 14:46:43 tv Exp $
#

DISTNAME=	trickle-1.06
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://monkey.org/~marius/trickle/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://monkey.org/~marius/trickle/
COMMENT=	Portable lightweight userspace bandwidth shaper

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/trickle
CONF_FILES=	${EGDIR}/trickled.conf ${PKG_SYSCONFDIR}/trickled.conf

RCD_SCRIPTS=	trickled

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/trickled.conf ${EGDIR}

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
