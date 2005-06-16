# $NetBSD: Makefile,v 1.2 2005/06/16 06:58:03 jlam Exp $
#

DISTNAME=		mairix-0.15.1
CATEGORIES=		mail
MASTER_SITES=		http://www.rpcurnow.force9.co.uk/mairix/

MAINTAINER=		tech-pkg@NetBSD.ORG
HOMEPAGE=		http://www.rc0.org.uk/mairix/
COMMENT=		Program for indexing and searching email messages

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

HAS_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--prefix=${PREFIX}

USE_MAKEINFO=		YES
INFO_FILES=		mairix.info

BINDIR=			${PREFIX}/bin
INFODIR=		${PREFIX}/info
HTMLDIR=		${PREFIX}/share/doc/html/mairix

INSTALLATION_DIRS=	bin info

pre-build:
			@cd ${WRKSRC}; \
			makeinfo mairix.texi; \
			${MAKEINFO} mairix.texi; \
			${MAKEINFO} --no-split --number-sections --html \
			    mairix.texi > mairix.html

do-install:
			${INSTALL_PROGRAM} ${WRKSRC}/mairix ${BINDIR}
			${INSTALL_DATA_DIR} ${HTMLDIR}
			${INSTALL_DATA} ${WRKSRC}/mairix.html ${HTMLDIR}
			${INSTALL_DATA} ${WRKSRC}/mairix.info ${INFODIR}

.include "../../mk/bsd.pkg.mk"
