# $NetBSD: Makefile,v 1.19 2012/10/03 21:56:21 wiz Exp $

DISTNAME=	clawsker-0.7.8
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/tools/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.claws-mail.org/clawsker
COMMENT=	Edit Claws-Mail hidden preferences

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake msgfmt perl
REPLACE_PERL=	clawsker

DEPENDS+=	p5-gtk2>=1.182:../../x11/p5-gtk2
DEPENDS+=	p5-gettext>=1.05nb2:../../devel/p5-gettext
DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mail/claws-mail/Makefile.vers"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
