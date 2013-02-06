# $NetBSD: Makefile,v 1.32 2013/02/06 23:23:34 jperkin Exp $
#

DISTNAME=		MyPasswordSafe-20061216
PKGREVISION=		16
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
