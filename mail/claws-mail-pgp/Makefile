# $NetBSD: Makefile,v 1.1 2007/08/03 02:34:53 smb Exp $
#
.include "../../mail/claws-mail/Makefile.vers"

DISTNAME=	claws-mail-pgp-${CLAWS_VERSION}
CATEGORIES=	mail security
MASTER_SITES=	# empty
DISTFILES=	# empy

MAINTAINER=	smb@NetBSD.org
COMMENT=	Metapackage for the PGP plug-in for Claws-mail

DEPENDS+=	claws-mail-pgpcore>=${CLAWS_VERSION}:../../mail/claws-mail-pgpcore
DEPENDS+=	claws-mail-pgpmime>=${CLAWS_VERSION}:../../mail/claws-mail-pgpmime
DEPENDS+=	claws-mail-pgpinline>=${CLAWS_VERSION}:../../mail/claws-mail-pgpinline

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
