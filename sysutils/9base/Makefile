# $NetBSD: Makefile,v 1.2 2005/12/06 18:50:36 rillig Exp $
#

DISTNAME=	9base-20051114
CATEGORIES=	sysutils shells
MASTER_SITES=	http://wmii.de/snaps/

MAINTAINER=	lems@gmx.net
HOMEPAGE=	http://wmii.de/
COMMENT=	Port of various original plan9 tools

CONFLICTS=		rc-[0-9]*

USE_PKGINSTALL=		yes
PKG_SHELL=		bin/rc

.include "../../mk/bsd.prefs.mk"

.if ${GNU_PROGRAM_PREFIX} == ""
CONFLICTS+=		coreutils-[0-9]*
CONFLICTS+=		grep-[0-9]*
CONFLICTS+=		gsed-[0-9]*
.endif

.include "../../mk/bsd.pkg.mk"
