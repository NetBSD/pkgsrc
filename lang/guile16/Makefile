# $NetBSD: Makefile,v 1.1.1.1 2007/06/04 23:38:40 dmcmahill Exp $

DISTNAME=		guile-1.6.8
PKGNAME=		guile16-1.6.8
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=guile/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/guile/guile.html
COMMENT=		GNU's Ubiquitous Intelligent Language for Extension (1.6.x series)

GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/guile/1.6
USE_TOOLS+=		gmake makeinfo
USE_LIBTOOL=		YES
USE_GNU_READLINE=	YES
PTHREAD_AUTO_VARS=	YES
INFO_FILES=		# PLIST

TEST_DIRS=		${WRKSRC}
TEST_TARGET=		check
OWN_DIRS=		${PREFIX}/share/guile/site

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CPPFLAGS+=		-Dmacosx

post-patch:
	@${MV} ${WRKSRC}/guile-config/guile-config.in.orig \
	    ${WRKSRC}/guile-config/guile-config.in
.endif

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
