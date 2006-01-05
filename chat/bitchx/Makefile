# $NetBSD: Makefile,v 1.39 2006/01/05 19:56:38 joerg Exp $

DISTNAME=	ircii-pana-1.1-final
PKGNAME=	bitchx-1.1
CATEGORIES=	chat
MASTER_SITES=	http://www.bitchx.org/files/source/ \
		ftp://ftp.bitchx.org/pub/BitchX/source/ \
		ftp://ftp.bitchx.org/pub/BitchX/source/old/

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://www.bitchx.org/
COMMENT=	IRC client based on ircII

# This package is not even remotely 64-bit clean
NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64 *-*-x86_64

WRKSRC=			${WRKDIR}/BitchX
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-ssl

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CFLAGS+=	-DBIND_8_COMPAT
.endif

SUBST_CLASSES+=		manpage
SUBST_FILES.manpage+=	doc/BitchX.1
SUBST_SED.manpage+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_STAGE.manpage+=	post-patch

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
