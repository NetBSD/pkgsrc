# $NetBSD: Makefile,v 1.5 2015/06/07 03:46:05 joerg Exp $
#

DISTNAME=	print-plist-0.0
CATEGORIES=	regress
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Test print-PLIST and related functionality

NO_CONFIGURE=	yes

WRKSRC=	${WRKDIR}

PRINT_PLIST_AWK+=	/^print-plist\/foo$$/ \
				{ print "@comment Matched test file."; \
				  print; next }

do-build:
	${ECHO} "foo" >${WRKDIR}/foo

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/print-plist
	${INSTALL_DATA} ${WRKDIR}/foo ${DESTDIR}${PREFIX}/print-plist

.include "../../mk/bsd.pkg.mk"
