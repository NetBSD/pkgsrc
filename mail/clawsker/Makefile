# $NetBSD: Makefile,v 1.6 2008/09/18 09:13:39 joerg Exp $

DISTNAME=	clawsker-0.5.0
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/tools/

MAINTAINER=	smb@NetBSD.org
HOMEPAGE=	http://www.claws-mail.org/clawsker
COMMENT=	Edit Claws-Mail hidden preferences

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake msgfmt perl
REPLACE_PERL=	clawsker

DEPENDS+=	p5-gtk2>=1.182:../../x11/p5-gtk2
DEPENDS+=	p5-gettext>=1.05:../../devel/p5-gettext
DEPENDS+=	claws-mail-3.5.0{,nb[0-9]*}:../../mail/claws-mail

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
