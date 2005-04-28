# $NetBSD: Makefile,v 1.1.1.1 2005/04/28 22:29:43 reed Exp $

DISTNAME=	foomatic-filters-3.0.2
CATEGORIES=	print
MASTER_SITES=	http://www.linuxprinting.org/download/foomatic/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.linuxprinting.org/
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

USE_GNU_TOOLS+=	make
USE_PERL5=	yes
USE_PKGINSTALL=	yes
PERL5_REQD=	5.6
INSTALL_TARGET=	install-bin install-man

PKG_SYSCONFSUBDIR=	foomatic
EGDIR=			${PREFIX}/share/examples/foomatic-filters/
CONF_FILES=		${EGDIR}/filter.conf ${PKG_SYSCONFDIR}/filter.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/filter.conf ${EGDIR}

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
