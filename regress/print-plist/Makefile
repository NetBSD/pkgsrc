# $NetBSD: Makefile,v 1.4 2009/04/09 00:47:12 joerg Exp $
#

DISTNAME=	print-plist-0.0
CATEGORIES=	regress
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Test print-PLIST and related functionality

NO_CONFIGURE=	yes

PRINT_PLIST_AWK+=	/^print-plist\/foo$$/ \
				{ print "@comment Matched test file."; \
				  print; next }
PRINT_PLIST_AWK+=	/^@dirrm print-plist$$/ \
				{ print "@comment Matched test directory."; \
				  print; next }

do-build:
	${ECHO} "foo" >${WRKDIR}/foo

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/print-plist
	${INSTALL_DATA} ${WRKDIR}/foo ${PREFIX}/print-plist

.include "../../mk/bsd.pkg.mk"
