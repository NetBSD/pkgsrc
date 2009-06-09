# $NetBSD: Makefile,v 1.4 2009/06/09 08:37:04 imil Exp $
#

DISTNAME=	ftwin-0.8.5
CATEGORIES=	sysutils
MASTER_SITES=	http://download.meroware.org/ftwin/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://jok.is-a-geek.net/ftwin.php
COMMENT=	Ftwin finds duplicate files according to their content

GNU_CONFIGURE=		yes

DOCDIR=			${PREFIX}/share/doc/ftwin

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	${DOCDIR} ${PKGMANDIR}/man8

post-install:
	${INSTALL_DATA} ${WRKSRC}/EXAMPLES ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/KNOWN_BUGS ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/check/buildlink3.mk"
.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/libpuzzle/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
