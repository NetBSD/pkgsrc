# $NetBSD: Makefile,v 1.12 2006/06/09 16:04:00 minskim Exp $
#

DISTNAME=		mairix-0.16.1
CATEGORIES=		mail
MASTER_SITES=		http://www.rpcurnow.force9.co.uk/mairix/

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://www.rc0.org.uk/mairix/
COMMENT=		Program for indexing and searching email messages

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

USE_TOOLS+=		bison flex makeinfo
INFO_FILES=		# PLIST

BINDIR=			${PREFIX}/bin
INFODIR=		${PREFIX}/${PKGINFODIR}
HTMLDIR=		${PREFIX}/share/doc/html/mairix

INSTALLATION_DIRS=	${BINDIR} ${INFODIR} ${HTMLDIR}

pre-build:
	cd ${WRKSRC} && makeinfo mairix.texi
	cd ${WRKSRC} && makeinfo --no-split --number-sections --html	\
		mairix.texi > mairix.html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mairix ${BINDIR}
	${INSTALL_DATA} ${WRKSRC}/mairix.html ${HTMLDIR}
	cd ${WRKSRC}; for f in mairix.info mairix.info-[0-9]; do	\
		${TEST} ! -f "$$f" || ${INSTALL_DATA} "$$f" ${INFODIR};	\
	done

.include "../../mk/bsd.pkg.mk"
