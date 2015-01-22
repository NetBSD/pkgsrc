# $NetBSD: Makefile,v 1.29 2015/01/22 20:46:58 wiz Exp $

DISTNAME=	ftwin-0.8.8
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://download.meroware.org/ftwin/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://jok.is-a-geek.net/ftwin.php
COMMENT=	Ftwin finds duplicate files according to their content

GNU_CONFIGURE=		yes

DOCDIR=			${PREFIX}/share/doc/ftwin

INSTALLATION_DIRS+=	${DOCDIR} ${PKGMANDIR}/man8

# 0.8.8 gives warnings with libarchive-3.x
BUILDLINK_TRANSFORM+=	rm:-Werror

post-install:
	${INSTALL_DATA} ${WRKSRC}/EXAMPLES ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/KNOWN_BUGS ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

TEST_TARGET=	check

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
BUILDLINK_DEPMETHOD.check=	build
.include "../../devel/check/buildlink3.mk"
.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/libpuzzle/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
