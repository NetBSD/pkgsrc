# $NetBSD: Makefile,v 1.51 2018/11/12 03:52:27 ryoon Exp $
#

DISTNAME=	cachesaver-0.10.9
PKGNAME=	claws-mail-cachesaver-0.10.9
PKGREVISION=	37
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins_obsolete/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Saves Claws-Mail metadata every 60 seconds

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
