# $NetBSD: Makefile,v 1.1.1.1 2004/09/08 15:04:23 jmmv Exp $
#

DISTNAME=	print-plist-0.0
CATEGORIES=	regress
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Test print-PLIST and related functionality

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_MTREE=	yes

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
