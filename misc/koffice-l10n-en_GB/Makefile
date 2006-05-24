# $NetBSD: Makefile,v 1.2 2006/05/24 12:57:53 markd Exp $

DISTNAME=	koffice-l10n-en_GB-1.5.1
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE:=koffice-1.5.1/src/koffice-l10n/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.koffice.org/
COMMENT=	English (Great Britain) language pack for KOffice

DEPENDS+=	kdelibs-[0-9]*:../../x11/kdelibs3
CONFLICTS+=	koffice-i18n-en_GB-[0-9]*

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../mk/bsd.pkg.mk"
