# $NetBSD: Makefile,v 1.15 2010/11/29 17:58:37 drochner Exp $
#
META_PACKAGE=	yes

.include "../../mail/claws-mail/Makefile.vers"

DISTNAME=	claws-mail-pgp-${CLAWS_VERSION}
CATEGORIES=	mail security
MASTER_SITES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Metapackage for the PGP plug-in for Claws-mail

DEPENDS+=	claws-mail-pgpcore-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail-pgpcore
DEPENDS+=	claws-mail-pgpmime-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail-pgpmime
DEPENDS+=	claws-mail-pgpinline-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail-pgpinline

.include "../../mk/bsd.pkg.mk"
