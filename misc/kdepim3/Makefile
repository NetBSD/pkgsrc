# $NetBSD: Makefile,v 1.23 2004/02/06 10:48:58 markd Exp $

DISTNAME=	kdepim-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	misc
COMMENT=	Personal Information Management tools for the KDE desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES
LIBTOOL_OVERRIDE+=	${WRKSRC}/libical/libtool

REPLACE_PERL=	kmail/kmail-3.1-update-new-mail-notification-settings.pl \
		kmail/kmail-3.1-use-UOID-for-identities.pl \
		kmail/kmail-3.1.4-dont-use-UOID-0-for-any-identity.pl \
		kmail/kmail-pgpidentity.pl \
		kmail/kmail-upd-identities.pl \
		kmail/upgrade-signature.pl \
		kmail/upgrade-transport.pl \
		libkdenetwork/kpgp-3.1-upgrade-address-data.pl

.include "../../comms/pilot-link-libs/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
