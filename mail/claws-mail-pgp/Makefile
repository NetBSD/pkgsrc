# $NetBSD: Makefile,v 1.13 2008/10/15 16:22:03 smb Exp $
#
META_PACKAGE=	yes

.include "../../mail/claws-mail/Makefile.vers"

DISTNAME=	claws-mail-pgp-${CLAWS_VERSION}
CATEGORIES=	mail security
MASTER_SITES=	# none

MAINTAINER=	smb@NetBSD.org
COMMENT=	Metapackage for the PGP plug-in for Claws-mail

DEPENDS+=	claws-mail-pgpcore-3.6.1{,nb[0-9]*}:../../mail/claws-mail-pgpcore
DEPENDS+=	claws-mail-pgpmime-3.6.1{,nb[0-9]*}:../../mail/claws-mail-pgpmime
DEPENDS+=	claws-mail-pgpinline-3.6.1{,nb[0-9]*}:../../mail/claws-mail-pgpinline

.include "../../mk/bsd.pkg.mk"
