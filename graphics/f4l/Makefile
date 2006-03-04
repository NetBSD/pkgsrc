# $NetBSD: Makefile,v 1.6 2006/03/04 21:29:47 jlam Exp $
#

DISTNAME=	f4l-0.2
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=f4l/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://f4l.sourceforge.net/
COMMENT=	Development environment for Macromedia Flash

NO_CONFIGURE=	yes

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/f4l ${PREFIX}/bin

.include "../../x11/qt3-tools/buildlink3.mk"
# XXX Please verify whether qt3-tools is really needed at run-time.
# If it is, then remove this comment.  If it is not, then remove
# this comment and the line below, and bump PKGREVISION.
BUILDLINK_DEPMETHOD.qt3-tools=	full
.include "../../mk/bsd.pkg.mk"
