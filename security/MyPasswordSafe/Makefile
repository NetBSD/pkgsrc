# $NetBSD: Makefile,v 1.37 2013/10/09 17:39:16 wiz Exp $
#

DISTNAME=		MyPasswordSafe-20061216
PKGREVISION=		21
CATEGORIES=		security
MASTER_SITES=		http://www.semanticgap.com/myps/release/
DISTFILES=		${DISTNAME}.src.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.semanticgap.com/myps/
COMMENT=		Easy-to-use password manager

.include "options.mk"

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
MAKE_FLAGS+=		QMAKE=${QTDIR:Q}/bin/qmake

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
