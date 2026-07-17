# $NetBSD: Makefile,v 1.14 2026/07/17 23:35:08 gdt Exp $

DISTNAME=	bulk-test-python27-20260717
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pksrc-users@NetBSD.org
COMMENT=	Meta-package for testing python 2.7

META_PACKAGE=	yes

RESTRICTED=		Just for test build purposes
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

# This package intends to contain every package which has both properties:
#   - it might break if python27 went missing
#   - some user might care
#
# We intentionally exclude "someone might have a private python 2.7 codebase that
# wants to use this as a dependency".

DEPENDS+=	python27-[0-9]*:../../lang/python27

DEPENDS+=	getmail5-[0-9]*:../../mail/getmail5
DEPENDS+=	mailman<3:../../mail/mailman

# does not support Python 3 yet
DEPENDS+=	py27-moin-[0-9]*:../../www/py-moin

.include "../../mk/bsd.pkg.mk"
