# $NetBSD: Makefile,v 1.32 2012/10/02 17:11:28 tron Exp $
#

DISTNAME=	spam_report-0.3.16
PKGNAME=	claws-mail-spam_report-0.3.16
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Report spam to various places

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
