# $NetBSD: Makefile,v 1.11 2025/10/21 07:04:30 wiz Exp $

DISTNAME=	bulk-test-python27-20251021
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

DEPENDS+=	arcticfox-[0-9]*:../../www/arcticfox
DEPENDS+=	getmail5-[0-9]*:../../mail/getmail5
DEPENDS+=	mailman<3:../../mail/mailman
DEPENDS+=	offlineimap-[0-9]*:../../mail/offlineimap
DEPENDS+=	palemoon-[0-9]*:../../www/palemoon
DEPENDS+=	mongodb-[0-9]*:../../databases/mongodb3

# does not support Python 3 yet
DEPENDS+=	py27-moin-[0-9]*:../../www/py-moin

.include "../../mk/bsd.pkg.mk"
