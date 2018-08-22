# $NetBSD: Makefile,v 1.8 2018/08/22 09:45:35 wiz Exp $

PKGREVISION= 1
.include "Makefile.common"

PKGNAME=	thunderbird-${DISTNAME}
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GnuPG support for mail/thunderbird

# Minimal requirements are here: https://www.enigmail.net/download/source.php
DEPENDS+=		thunderbird>=38:../../mail/thunderbird

# Path used during the install stage
XPIDIR=		${PREFIX}/lib/thunderbird/extensions

.include "../../mk/bsd.pkg.mk"
