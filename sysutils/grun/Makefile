# $NetBSD: Makefile,v 1.32 2012/10/02 17:11:59 tron Exp $

DISTNAME=	grun-0.9.3
PKGREVISION=	12
CATEGORIES=	misc
MASTER_SITES=	http://grun.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/grun/
COMMENT=	GTK+ based Run dialog

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_SYSCONFSUBDIR=	grun
EGDIR=			${PREFIX}/share/examples/grun
CONF_FILES=		${EGDIR}/gassoc ${PKG_SYSCONFDIR}/gassoc
CONF_FILES+=		${EGDIR}/consfile ${PKG_SYSCONFDIR}/consfile
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/grun

post-install:
	${INSTALL_MAN} ${WRKSRC}/grun.1x \
		${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1/grun.1
	${INSTALL_DATA} ${WRKSRC}/gassoc ${DESTDIR}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/consfile ${DESTDIR}/${EGDIR}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
