# $NetBSD: Makefile,v 1.32 2016/03/05 11:28:49 jperkin Exp $
#

DISTNAME=		netbiff-0.9.18
PKGREVISION=		26
CATEGORIES=		mail
MASTER_SITES=		http://www.cs.virginia.edu/~jrk3g/netbiff/

MAINTAINER=		rvalls@ac.upc.edu
HOMEPAGE=		http://www.cs.virginia.edu/~jrk3g/netbiff/
COMMENT=		Xbiff-like mail notification, handles multiple mailboxes

USE_TOOLS+=		pkg-config

LDFLAGS.SunOS+=		-lsocket -lnsl

SUBST_CLASSES+=		fix-path
SUBST_FILES.fix-path+=	conf-home
SUBST_STAGE.fix-path=	pre-configure
SUBST_SED.fix-path=	-e 's|/usr/local|${PREFIX}|g'

DOCDIR=			${DESTDIR}${PREFIX}/share/doc/netbiff

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/CONFIG ${DOCDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
