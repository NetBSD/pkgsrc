# $NetBSD: Makefile,v 1.5 2016/05/05 12:06:38 wiz Exp $

.include "Makefile.common"

PKGNAME=	thunderbird-${DISTNAME}
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GnuPG support for mail/thunderbird

# Minimal requirements are here: https://www.enigmail.net/download/source.php
DEPENDS+=		thunderbird>=38:../../mail/thunderbird

# Path used during the install stage
XPIDIR=		${PREFIX}/lib/thunderbird/extensions

.include "../../mk/bsd.pkg.mk"
