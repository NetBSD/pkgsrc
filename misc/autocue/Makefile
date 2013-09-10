# $NetBSD: Makefile,v 1.9 2013/09/10 14:23:45 joerg Exp $
#

DISTNAME=	autocue-20070224
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.alistaircrooks.co.uk/software.html
COMMENT=	Time-based text formatter, sending output to xcb for pasting

DEPENDS+=	xcb-[0-9]*:../../x11/xcb

USE_FEATURES+=	cdefs

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/autocue ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/autocue.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
BUILDLINK_TRANSFORM+=	rm:-Wno-traditional
CFLAGS+=	-Wno-invalid-source-encoding
.endif

.include "../../mk/bsd.pkg.mk"
