# $NetBSD: Makefile,v 1.6 2006/03/04 21:30:39 jlam Exp $
#

DISTNAME=	9base-20051114
CATEGORIES=	sysutils shells
MASTER_SITES=	http://wmii.de/snaps/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wmii.de/
COMMENT=	Port of various original plan9 tools

CONFLICTS=		rc-[0-9]*

PKG_SHELL=		bin/rc

.include "../../mk/bsd.prefs.mk"

# Darwin doesn't support static link. 
# See http://developer.apple.com/qa/qa2001/qa1118.html
.if ${OPSYS} != "Darwin"
LDFLAGS+= -static
.endif

.if ${GNU_PROGRAM_PREFIX} == ""
CONFLICTS+=		coreutils-[0-9]*
CONFLICTS+=		grep-[0-9]*
CONFLICTS+=		gsed-[0-9]*
.endif

.include "../../mk/bsd.pkg.mk"
