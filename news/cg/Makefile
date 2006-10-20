# $NetBSD: Makefile,v 1.9 2006/10/20 19:18:45 schwarz Exp $
#

DISTNAME=	cg-0.4
CATEGORIES=	news
MASTER_SITES=	http://ftp.giga.or.at/pub/nih/cg/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://ftp.giga.or.at/pub/nih/cg/
COMMENT=	Semi-automatic newsgroup binary downloader

GNU_CONFIGURE=		YES
USE_TOOLS+=		lex
TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"
.if !empty(LOWER_OPSYS:Mirix5*)
# needs regex.h
. include "../../pkgtools/libnbcompat/buildlink3.mk"
SUBST_CLASSES+=         regex_h
SUBST_STAGE.regex_h=     post-patch
SUBST_FILES.regex_h=     checkgroup.c
SUBST_SED.regex_h=       -e "s,<regex\.h>,<nbcompat/regex.h>,"
.endif
.include "../../mk/bsd.pkg.mk"
