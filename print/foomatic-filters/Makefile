# $NetBSD: Makefile,v 1.5 2005/10/10 20:30:07 reed Exp $

DISTNAME=	foomatic-filters-3.0.2
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.linuxprinting.org/download/foomatic/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.linuxprinting.org/foomatic.html
COMMENT=	Spooler independent postscript printing filter

# You may choose from any of the following, if you wish
DEPENDS+=	mpage-[0-9]*:../../print/mpage
#DEPENDS+=	a2ps-[0-9]*:../../print/a2ps
#DEPENDS+=	enscript-[0-9]*:../../print/enscript

CONFLICTS+=	foomatic-gswrapper-[0-9]

GNU_CONFIGURE=		YES
CONFIG_GUESS_OVERRIDE=  ${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=    ${WRKSRC}/config.sub

# Rather than wrestle with the maintainer's horribly broken configure
# scripts, we just override everything here
CONFIGURE_ENV+= 	CUPS=${LOCALBASE}/share/cups
CONFIGURE_ENV+= 	CUPS_FILTERS=${LOCALBASE}/lib/cups/filter
CONFIGURE_ENV+= 	PRINTCAP=/etc/printcap
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}

USE_TOOLS+=	gmake perl:run
USE_PKGINSTALL=	yes
INSTALL_TARGET=	install-bin install-man

PKG_SYSCONFSUBDIR=	foomatic
EGDIR=			${PREFIX}/share/examples/foomatic-filters/
CONF_FILES=		${EGDIR}/filter.conf ${PKG_SYSCONFDIR}/filter.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/filter.conf ${EGDIR}

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
