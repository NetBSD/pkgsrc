# $NetBSD: Makefile,v 1.10 2007/10/25 22:01:06 jlam Exp $
#

DISTNAME=	chasen-${CHASEN_VERSION}
CATEGORIES=	japanese textproc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://chasen-legacy.sourceforge.jp/
COMMENT=	meta package of ChaSen, Japanese Morphological Analysis System

DEPENDS+=	chasen-base>=${CHASEN_VERSION}:../../textproc/chasen-base
DEPENDS+=	ipadic>=2.6.3:../../textproc/ipadic

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SRC=	# empty (meta-package)

PKG_DESTDIR_SUPPORT=	user-destdir

do-install:	# empty

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
