# $NetBSD: Makefile,v 1.32 2023/11/15 08:22:59 wiz Exp $

DISTNAME=	clawsker-1.3.7
CATEGORIES=	mail
MASTER_SITES=	https://www.claws-mail.org/tools/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.claws-mail.org/clawsker
COMMENT=	Edit Claws-Mail hidden preferences
LICENSE=	gnu-gpl-v3

DEPENDS+=	p5-gtk3>=0.030:../../x11/p5-gtk3
DEPENDS+=	p5-gettext>=1.05nb2:../../devel/p5-gettext
DEPENDS+=	p5-File-Which>=1.21:../../devel/p5-File-Which
DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail
TEST_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception
# unpackaged test dependency: Test::NeedsDisplay

USE_TOOLS+=	gmake msgfmt perl
REPLACE_PERL=	clawsker

TEST_TARGET=	test

INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/claws-mail/Makefile.vers"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
