# $NetBSD: Makefile,v 1.26 2010/10/03 12:24:19 obache Exp $
#

DISTNAME=	tnt-1.9.2
CATEGORIES=	ham
MASTER_SITES=	ftp://ftp.wspse.de/pub/packet_radio/tnt/

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://wspse.de/WSPse/Packet.php3
COMMENT=	Amateur packet radio terminal program for TNC2, AEA PK232 and PK88

DEPENDS+=	dialog>=0.6z:../../misc/dialog

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

SUBST_CLASSES+=		missing
SUBST_MESSAGE.missing=	Subst missing replacements with configure
SUBST_STAGE.missing=	post-configure
SUBST_FILES.missing=	intl/Makefile
SUBST_SED.missing=	-e 's,@GT_YES@,\#,g'
SUBST_SED.missing+=	-e 's,@GT_NO@,,g'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
