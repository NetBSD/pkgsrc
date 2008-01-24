# $NetBSD: Makefile,v 1.1 2008/01/24 03:00:28 smb Exp $

DISTNAME=	clawsker-0.3.0
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/tools/

MAINTAINER=	smb@NetBSD.org
HOMEPAGE=	http://www.claws-mail.org/clawsker
COMMENT=	Edit Claws-Mail hidden preferences

USE_TOOLS+=	gmake
USE_TOOLS+=	perl
REPLACE_PERL=	clawsker

DEPENDS+=	p5-gtk2>=1.144:../../x11/p5-gtk2
DEPENDS+=	p5-gettext>=1.05:../../devel/p5-gettext
DEPENDS+=	claws-mail-3.2.0{,nb[0-9]*}:../../mail/claws-mail

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
