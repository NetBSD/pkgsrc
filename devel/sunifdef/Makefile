# $NetBSD: Makefile,v 1.11 2019/08/11 13:20:51 wiz Exp $
#

DISTNAME=	sunifdef-3.1.3
PKGREVISION=	7
CATEGORIES=	devel
#MASTER_SITES=	http://www.strudl.org/public_ftp/sunifdef/nix/stable/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.strudl.org/public_ftp/sunifdef/nix/stable/
COMMENT=	Tool for eliminating superfluous C preprocessor conditionals

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

HTMLDIR=	${PREFIX}/share/doc/${PKGBASE}/html

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss]) || make(test)
USE_TOOLS+=		perl
TEST_TARGET=		check
.endif

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/man/html/sunifdef_man_1.html \
		${DESTDIR}${HTMLDIR}/${PKGBASE}_man_1.html

.include "../../mk/bsd.pkg.mk"
