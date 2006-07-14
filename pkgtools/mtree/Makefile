# $NetBSD: Makefile,v 1.18 2006/07/14 19:23:09 jlam Exp $
#

DISTNAME=		mtree-20040722
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Utility for mapping and checking directory hierarchies

GNU_CONFIGURE=		yes

NO_PKGTOOLS_REQD_CHECK=	# defined
NO_CHECKSUM=		yes
NO_MTREE=		yes
PKG_PRESERVE=		# defined

.include "../../mk/bsd.prefs.mk"

PKG_TOOLS_PREFIX=	${PKG_TOOLS_BIN:C|/[^/]?bin$||}

# XXX This breaks for those who set their own LOCALBASE to "/usr" and also
# XXX set PKGMANDIR to be other than "share/man".
# XXX
.if !empty(PKG_TOOLS_PREFIX:M/usr)
PKGMANDIR=		share/man
.endif

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.if defined(LIBNBCOMPAT_STYLE) && (${LIBNBCOMPAT_STYLE} == "inplace")
.  include "../../pkgtools/libnbcompat/inplace.mk"
.else
.  include "../../pkgtools/libnbcompat/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"

PREFIX:=	${PKG_TOOLS_PREFIX}
