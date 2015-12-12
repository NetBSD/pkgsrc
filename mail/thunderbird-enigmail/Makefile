# $NetBSD: Makefile,v 1.2 2015/12/12 01:28:15 ryoon Exp $

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
