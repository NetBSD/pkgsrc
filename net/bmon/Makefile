# $NetBSD: Makefile,v 1.12 2013/08/09 18:15:18 riastradh Exp $
#

DISTNAME=	bmon-2.0.1
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://people.suug.ch/~tgr/bmon/files/

MAINTAINER=	hsaliak@gmail.com
HOMEPAGE=	http://people.suug.ch/~tgr/bmon/
COMMENT=	Bmon is an interface bandwidth monitor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile
USE_TOOLS+=	gmake

# In NetBSD 1.6.x the native curses implementation has problems with bmon.
# So mark it as incompatible and link bmon against the
# 3rd party ncurses library in NetBSD 1.6.x.
INCOMPAT_CURSES= NetBSD-1.6*-*

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
