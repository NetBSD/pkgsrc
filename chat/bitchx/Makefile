# $NetBSD: Makefile,v 1.9.2.1 2002/06/23 18:40:29 jlam Exp $

DISTNAME=	ircii-pana-1.0c18
PKGNAME=	bitchx-1.0.3.18
WRKSRC=		${WRKDIR}/BitchX
CATEGORIES=	chat

# /old/ is for when pkgsrc is not up to date
MASTER_SITES=	ftp://ftp.bitchx.org/pub/BitchX/source/ \
		ftp://ftp.bitchx.org/pub/BitchX/source/old/

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://www.bitchx.org/
COMMENT=	IRC client based on ircII

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl

# Files are installed using a .bz2 extension, and BitchX assumes it can
# find bunzip2 in the PATH.
#
.if !exists(/usr/bin/bunzip2)
DEPENDS+=		bzip2>=0.9:../../archivers/bzip2
.endif

# We don't need the CVS files, and if we don't delete them, they get
# installed later on; ignore error code, since we delete the directories
# before find can descend into them.
post-extract:
	( ${FIND} ${WRKDIR}/BitchX/bitchx-docs -type d -name CVS -print \
		| ${XARGS} ${RM} -rf ) 2>/dev/null

# The WANT_NOTIFY_BITCHX_COM message after configure is misleading, we
# disable this by default.
post-configure:
	@${ECHO}
	@${ECHO} ===== WANT_NOTIFY_BITCHX_COM is disabled by default =====
	@${ECHO}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/BitchX.1 ${PREFIX}/man/man1
	# delete installed bzip2'd man page
	${RM} ${PREFIX}/man/man1/BitchX.1.bz2
	${INSTALL_DATA} ${WRKSRC}/doc/BitchX.doc ${PREFIX}/share/bx

.include "../../devel/ncurses/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
