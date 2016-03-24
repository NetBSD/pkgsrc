# $NetBSD: Makefile,v 1.4 2016/03/24 03:32:37 ryoon Exp $

.include "Makefile.common"

PKGNAME=	thunderbird-${DISTNAME}
PKGREVISION=	1
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GnuPG support for mail/thunderbird

# Minimal requirements are here: https://www.enigmail.net/download/source.php
DEPENDS+=		thunderbird>=31:../../mail/thunderbird

# Path used during the install stage
XPIDIR=		${PREFIX}/lib/thunderbird/extensions

.include "../../mk/bsd.pkg.mk"
