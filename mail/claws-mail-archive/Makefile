# $NetBSD: Makefile,v 1.2 2008/09/26 17:51:17 smb Exp $
#

DISTNAME=	archive-0.6
PKGNAME=	claws-mail-archive-0.6
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/
PKGREVISION=	1

MAINTAINER=	smb@NetBSD.org
COMMENT=	Adds archiving to Claws-Mail

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	claws-mail-3.5.0{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
