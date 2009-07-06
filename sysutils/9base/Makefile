# $NetBSD: Makefile,v 1.10 2009/07/06 16:08:05 joerg Exp $
#

DISTNAME=	9base-20051114
CATEGORIES=	sysutils shells
MASTER_SITES=	http://www.suckless.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.suckless.org/wiki/wmii/download
COMMENT=	Port of various original plan9 tools

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

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

post-extract:
	${LN} -s getcallerpc-x86_64.c ${WRKSRC}/lib9/getcallerpc-amd64.c

.include "../../mk/bsd.pkg.mk"
