
PKGNAME=	postgresql80-${BASE_VERS}
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql80-client>=${BASE_VERS}:../../wip/postgresql80-client
DEPENDS+=	postgresql80-server>=${BASE_VERS}:../../wip/postgresql80-server
DEPENDS+=	postgresql80-docs>=${BASE_VERS}:../../wip/postgresql80-docs

.include "Makefile.common"

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

do-install:	# empty
do-patch:	# empty

.include "../../mk/bsd.pkg.mk"
