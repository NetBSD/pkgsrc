# $NetBSD: Makefile,v 1.4 2007/10/25 22:00:57 jlam Exp $
#

DISTNAME=	pkgsrc-guide-tools-1.0
PKGREVISION=	1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Packages required to build the pkgsrc Guide

_GUIDE_DEPTYPE=	run

.include "../../doc/guide/Makefile.common"

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SRC=	# empty (meta-package)

do-install:
	@${DO_NADA}

.include "../../mk/bsd.pkg.mk"
