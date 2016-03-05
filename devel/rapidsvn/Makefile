# $NetBSD: Makefile,v 1.85 2016/03/05 11:28:25 jperkin Exp $

DISTNAME=		rapidsvn-0.12.1
PKGREVISION=		18
CATEGORIES=		devel x11 scm
MASTER_SITES=		http://www.rapidsvn.org/download/release/0.12.1/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://rapidsvn.tigris.org/
COMMENT=		Cross-platform Subversion GUI
LICENSE=		gnu-gpl-v3

USE_TOOLS+=		gmake msgfmt
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-svn-include=${BUILDLINK_DIR}/include
CONFIGURE_ARGS+=	--with-svn-lib=${BUILDLINK_DIR}/lib
CONFIGURE_ARGS+=	--with-doxygen=no

# While apr is actually a dependency, we ride it being included via
# subversion-base, following the precedent of devel/foo-subversion and
# www/ap2-subversion.
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
