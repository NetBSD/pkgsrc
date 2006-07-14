# $NetBSD: Makefile,v 1.11 2006/07/14 22:13:19 jlam Exp $

DISTNAME=	pkgmanpages-20050911
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.pkgsrc.org/
COMMENT=	Manual page(s) for the packages collection

NO_PKGTOOLS_REQD_CHECK=	# defined
PKG_PRESERVE=		# defined

NO_CHECKSUM=	yes
NO_MTREE=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	${PKGMANDIR}/man7

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

do-install:
	${INSTALL_MAN} ${WRKSRC}/packages.7 ${PREFIX}/${PKGMANDIR}/man7

.include "../../mk/bsd.pkg.mk"

PREFIX:=	${PKG_TOOLS_PREFIX}
