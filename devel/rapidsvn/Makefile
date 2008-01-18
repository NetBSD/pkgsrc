# $NetBSD: Makefile,v 1.35 2008/01/18 05:14:38 tnn Exp $

DISTNAME=		rapidsvn-0.9.4
PKGREVISION=		3
CATEGORIES=		devel x11 scm
MASTER_SITES=		http://www.rapidsvn.org/download/release/0.9.4/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://rapidsvn.tigris.org/
COMMENT=		Cross-platform Subversion GUI

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-svn-include=${BUILDLINK_DIR}/include
CONFIGURE_ARGS+=	--with-svn-lib=${BUILDLINK_DIR}/lib

INSTALLATION_DIRS+=	include/svncpp

post-configure:
	${ECHO} 'all:' > ${WRKSRC}/doc/manpage/Makefile
	${ECHO} 'install:' >> ${WRKSRC}/doc/manpage/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/manpage/rapidsvn.1 \
		${PREFIX}/${PKGMANDIR}/man1


.include "../../devel/apr0/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
