# $NetBSD: Makefile,v 1.27 2018/08/22 09:45:23 wiz Exp $

DISTNAME=	clawsker-0.7.8
PKGREVISION=	7
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/tools/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.claws-mail.org/clawsker
COMMENT=	Edit Claws-Mail hidden preferences

USE_TOOLS+=	gmake msgfmt perl
REPLACE_PERL=	clawsker

DEPENDS+=	p5-gtk2>=1.182:../../x11/p5-gtk2
DEPENDS+=	p5-gettext>=1.05nb2:../../devel/p5-gettext
DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mail/claws-mail/Makefile.vers"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
