# $NetBSD: Makefile,v 1.12 2008/09/26 17:51:17 smb Exp $
#
META_PACKAGE=	yes

.include "../../mail/claws-mail/Makefile.vers"

DISTNAME=	claws-mail-pgp-${CLAWS_VERSION}
CATEGORIES=	mail security
MASTER_SITES=	# none
PKGREVISION=	1

MAINTAINER=	smb@NetBSD.org
COMMENT=	Metapackage for the PGP plug-in for Claws-mail

DEPENDS+=	claws-mail-pgpcore-3.5.0{,nb[0-9]*}:../../mail/claws-mail-pgpcore
DEPENDS+=	claws-mail-pgpmime-3.5.0{,nb[0-9]*}:../../mail/claws-mail-pgpmime
DEPENDS+=	claws-mail-pgpinline-3.5.0{,nb[0-9]*}:../../mail/claws-mail-pgpinline

.include "../../mk/bsd.pkg.mk"
