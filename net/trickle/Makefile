# $NetBSD: Makefile,v 1.2 2003/09/27 02:31:48 xtraeme Exp $
#

DISTNAME=	trickle-1.06
CATEGORIES=	net
MASTER_SITES=	http://monkey.org/~marius/trickle/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://monkey.org/~marius/trickle/
COMMENT=	Portable lightweight userspace bandwidth shaper

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/trickle
CONF_FILES=	${EGDIR}/trickled.conf ${PKG_SYSCONFDIR}/trickled.conf

RCD_SCRIPTS=	trickled

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/trickled.conf ${EGDIR}

.include "../../devel/libevent/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
