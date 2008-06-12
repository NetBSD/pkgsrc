# $NetBSD: Makefile,v 1.9 2008/06/12 02:14:34 joerg Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mail/claws-mail/Makefile.vers"

DISTNAME=	claws-mail-pgp-${CLAWS_VERSION}
CATEGORIES=	mail security
MASTER_SITES=	# none

MAINTAINER=	smb@NetBSD.org
COMMENT=	Metapackage for the PGP plug-in for Claws-mail

DEPENDS+=	claws-mail-pgpcore-3.4.0{,nb[0-9]*}:../../mail/claws-mail-pgpcore
DEPENDS+=	claws-mail-pgpmime-3.4.0{,nb[0-9]*}:../../mail/claws-mail-pgpmime
DEPENDS+=	claws-mail-pgpinline-3.4.0{,nb[0-9]*}:../../mail/claws-mail-pgpinline

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
