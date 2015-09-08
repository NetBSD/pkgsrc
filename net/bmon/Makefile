# $NetBSD: Makefile,v 1.16 2015/09/08 11:57:50 jperkin Exp $
#

DISTNAME=	bmon-2.0.1
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://people.suug.ch/~tgr/bmon/files/

MAINTAINER=	hsaliak@gmail.com
HOMEPAGE=	http://people.suug.ch/~tgr/bmon/
COMMENT=	Bmon is an interface bandwidth monitor

GNU_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/bmon
CONF_FILES=	${EGDIR}/bmon.conf ${PKG_SYSCONFDIR}/bmon.conf

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/bmon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/bmon ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/bmon.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/etc/bmon.conf	\
	    ${DESTDIR}${PREFIX}/share/examples/bmon/bmon.conf

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
