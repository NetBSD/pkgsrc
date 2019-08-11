# $NetBSD: Makefile,v 1.7 2019/08/11 13:21:41 wiz Exp $

PKGREVISION= 2
.include "../../mail/thunderbird-enigmail/Makefile.common"

PKGNAME=	seamonkey-${DISTNAME}
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GnuPG support for www/seamonkey

# Minimal requirements are here: https://www.enigmail.net/download/source.php
DEPENDS+=		seamonkey>=2.35:../../www/seamonkey

# Path used during the install stage
XPIDIR=		${PREFIX}/lib/seamonkey/extensions

.include "../../mk/bsd.pkg.mk"
