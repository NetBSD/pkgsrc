# $NetBSD: Makefile,v 1.6 2018/08/22 09:45:34 wiz Exp $

PKGREVISION= 1
.include "../../mail/thunderbird-enigmail/Makefile.common"

PKGNAME=	seamonkey-${DISTNAME}
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GnuPG support for www/seamonkey

# Minimal requirements are here: https://www.enigmail.net/download/source.php
DEPENDS+=		seamonkey>=2.35:../../www/seamonkey

# Path used during the install stage
XPIDIR=		${PREFIX}/lib/seamonkey/extensions

.include "../../mk/bsd.pkg.mk"
