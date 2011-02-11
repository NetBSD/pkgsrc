# $NetBSD: Makefile,v 1.22 2011/02/11 21:22:03 tnn Exp $
#

DISTNAME=	trickle-1.06
PKGREVISION=	12
CATEGORIES=	net
MASTER_SITES=	http://monkey.org/~marius/trickle/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://monkey.org/~marius/trickle/
COMMENT=	Portable lightweight userspace bandwidth shaper

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/trickle
CONF_FILES=	${EGDIR}/trickled.conf ${PKG_SYSCONFDIR}/trickled.conf

RCD_SCRIPTS=	trickled
INSTALLATION_DIRS+=	${EGDIR}

pre-install:
	${INSTALL_DATA} ${FILESDIR}/trickled.conf ${DESTDIR}${EGDIR}

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
