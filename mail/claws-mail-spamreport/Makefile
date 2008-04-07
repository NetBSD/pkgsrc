# $NetBSD: Makefile,v 1.6 2008/04/07 16:51:18 joerg Exp $
#

DISTNAME=	spam_report-0.3.1
PKGNAME=	claws-mail-spam_report-0.3.1
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://claws-mail.org/downloads/plugins/

MAINTAINER=	smb@NetBSD.org
COMMENT=	Report spam to various places

DEPENDS+=	claws-mail-3.2.0{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/claws-mail/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
