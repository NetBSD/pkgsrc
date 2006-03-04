# $NetBSD: Makefile,v 1.25 2006/03/04 21:29:29 jlam Exp $

DISTNAME=		rapidsvn-0.9.0
PKGREVISION=		2
CATEGORIES=		devel x11
MASTER_SITES=		http://www.rapidsvn.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://rapidsvn.tigris.org/
COMMENT=		Cross-platform Subversion GUI

USE_TOOLS+=		gmake
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


.include "../../devel/apr/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
