# $NetBSD: Makefile,v 1.1 2006/10/17 09:44:06 markd Exp $

DISTNAME=	koffice-l10n-da-1.6.0
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE:=koffice-1.6.0/src/koffice-l10n/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.koffice.org/
COMMENT=	Danish language pack for KOffice

DEPENDS+=	koffice-[0-9]*:../../misc/koffice
CONFLICTS+=	koffice-i18n-da-[0-9]*

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../mk/bsd.pkg.mk"
