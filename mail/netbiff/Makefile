# $NetBSD: Makefile,v 1.2 2008/02/04 19:52:54 tnn Exp $
#

DISTNAME=		netbiff-0.9.18
CATEGORIES=		mail
MASTER_SITES=		http://www.cs.virginia.edu/~jrk3g/netbiff/

MAINTAINER=		rvalls@ac.upc.edu
HOMEPAGE=		http://www.cs.virginia.edu/~jrk3g/netbiff/
COMMENT=		Xbiff-like mail notification, handles multiple mailboxes

USE_TOOLS+=		pkg-config

SUBST_CLASSES+=		fix-path
SUBST_FILES.fix-path+=	conf-home
SUBST_STAGE.fix-path=	pre-configure
SUBST_SED.fix-path=	-e 's|/usr/local|${PREFIX}|g'

DOCDIR=			${DESTDIR}${PREFIX}/share/doc/netbiff

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/CONFIG ${DOCDIR}

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
