# $NetBSD: Makefile,v 1.1 2015/07/01 12:54:32 ryoon Exp $

.include "Makefile.common"

PKGNAME=	thunderbird-${DISTNAME}
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GnuPG support for mail/thunderbird

# Minimal requirements are here: https://www.enigmail.net/download/source.php
DEPENDS+=		thunderbird>=31:../../mail/thunderbird

# Path used during the install stage
XPIDIR=		${PREFIX}/lib/thunderbird/extensions

.include "../../mk/bsd.pkg.mk"
