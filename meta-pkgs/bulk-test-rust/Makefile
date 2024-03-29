# $NetBSD: Makefile,v 1.5 2023/08/25 21:58:54 gutteridge Exp $

DISTNAME=	bulk-test-rust-20230825.2
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

# Feel free to add packages without asking me.
MAINTAINER=	gdt@NetBSD.org
COMMENT=	Meta-package for testing rust

META_PACKAGE=	yes

RESTRICTED=		Just for test build purposes
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

# Prorams should be listed here if they are maintained upstream and
# updated reasonably promptly in pkgsrc.  (Alternatively, programs
# that are actively maintained in pkgsrc despite being unmaintained
# upstream are acceptable.)  (This package is about catching
# regressions, and not about pressuring programs that have not
# recently and usually been healthy.)

# Limit to one python version; we only care if rust can build the rust
# files within the package.
PYTHON_VERSIONS_ACCEPTED=	${PYTHON_VERSION_DEFAULT}
PYTHON_VERSIONS_INCOMPATIBLE=	27
.include "../../lang/python/pyversion.mk"

# enormous programs
DEPENDS+=	thunderbird-[0-9]*:../../mail/thunderbird
DEPENDS+=	firefox-[0-9]*:../../www/firefox
DEPENDS+=	firefox-esr-[0-9]*:../../www/firefox-esr

# moderate programs
DEPENDS+=	matrix-synapse-[0-9]*:../../chat/matrix-synapse
DEPENDS+=	vaultwarden-[0-9]*:../../security/vaultwarden
DEPENDS+=	arti-[0-9]*:../../net/arti

# libraries
DEPENDS+=	libimagequant-[0-9]*:../../graphics/libimagequant
DEPENDS+=	librsvg-[0-9]*:../../graphics/librsvg
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography

.include "../../mk/bsd.pkg.mk"
