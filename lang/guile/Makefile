# $NetBSD: Makefile,v 1.66 2005/10/16 21:01:19 gdt Exp $

DISTNAME=		guile-1.6.7
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=guile/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/guile/guile.html
COMMENT=		GNU's Ubiquitous Intelligent Language for Extension

CONFLICTS=		guile14<1.4.1nb1 guile-oops-[0-9]*

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
USE_GNU_READLINE=	YES
PTHREAD_AUTO_VARS=	YES

USE_MAKEINFO=		YES
INFO_FILES=		guile.info guile-tut.info goops.info r5rs.info

TEST_DIRS=		${WRKSRC}
TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CPPFLAGS+=		-Dmacosx

post-patch:
	@${MV} ${WRKSRC}/guile-config/guile-config.in.orig \
	    ${WRKSRC}/guile-config/guile-config.in
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/guile/site

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
