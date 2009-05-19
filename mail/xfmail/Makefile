# $NetBSD: Makefile,v 1.45 2009/05/19 08:59:23 wiz Exp $

DISTNAME=		xfmail-1.5.5
PKGREVISION=		1
CATEGORIES=		mail x11
MASTER_SITES=		ftp://xfmail.ufies.org/pub/xfmail/release/1.5.5/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xfmail.slappy.org/
COMMENT=		Xforms based mail application for Unix operating systems
#LICENSE=		gpl-gnu-v2
# A few files are.
#LICENSE+=		mit-license

USE_X11BASE=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xfmail
	${INSTALL_DATA} ${WRKSRC}/Copyright ${PREFIX}/share/doc/xfmail

.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
