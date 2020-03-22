# $NetBSD: Makefile,v 1.36 2020/03/22 18:38:27 rillig Exp $

DISTNAME=	mhash-0.9.9
PKGREVISION=	10
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mhash/}
EXTRACT_SUFX=	.tar.bz2

PATCHFILES+=	mhash-freebsd-patches-20081108.diff.gz
PATCH_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mhash.sourceforge.net/
COMMENT=	Hash algorithms library

USE_TOOLS+=		gmake perl autoconf
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	include/mutils

POLLUTING_SYMS=		MD4Final MD4Init MD4Transform MD4Update \
			MD5Final MD5Init MD5Transform MD5Update

SUBST_CLASSES+=		ns
SUBST_STAGE.ns=		pre-configure
SUBST_MESSAGE.ns=	Prefixing symbols to avoid libc namespace pollution
SUBST_FILES.ns=		lib/*.c lib/*.h
.for sym in ${POLLUTING_SYMS}
SUBST_SED.ns+=		-e 's,\(${sym}\),mhash_\1,g'
.endfor

pre-configure:
	cd ${WRKSRC} && autoconf -v -f

.include "../../mk/bsd.pkg.mk"
