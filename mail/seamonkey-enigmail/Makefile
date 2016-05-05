# $NetBSD: Makefile,v 1.5 2016/05/05 12:06:38 wiz Exp $

.include "../../mail/thunderbird-enigmail/Makefile.common"

PKGNAME=	seamonkey-${DISTNAME}
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GnuPG support for www/seamonkey

# Minimal requirements are here: https://www.enigmail.net/download/source.php
DEPENDS+=		seamonkey>=2.35:../../www/seamonkey

# Path used during the install stage
XPIDIR=		${PREFIX}/lib/seamonkey/extensions

.include "../../mk/bsd.pkg.mk"
