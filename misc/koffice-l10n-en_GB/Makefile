# $NetBSD: Makefile,v 1.1 2006/04/12 13:01:41 markd Exp $

DISTNAME=	koffice-l10n-en_GB-1.5.0
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE:=koffice-1.5.0/src/koffice-l10n/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.koffice.org/
COMMENT=	English (Great Britain) language pack for KOffice

DEPENDS+=	kdelibs-[0-9]*:../../x11/kdelibs3
CONFLICTS+=	koffice-i18n-en_GB-[0-9]*

BUILD_USES_MSGFMT=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../mk/bsd.pkg.mk"
