# $NetBSD: Makefile,v 1.26 2014/06/18 09:26:11 wiz Exp $

.include "Makefile.common"

DISTNAME=	foomatic-filters-${FOOMATIC_FILTERS_VERSION}
PKGREVISION=	9
MASTER_SITES=	http://www.linuxprinting.org/download/foomatic/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spooler-independent PostScript printing filter
LICENSE=	gnu-gpl-v2

CONFLICTS+=	foomatic-gswrapper-[0-9]*

USE_TOOLS+=	gmake gs:run perl:run

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--disable-file-converter-check

EVAL_PREFIX+=		CUPS_PREFIX=cups
CUPS_FILTERDIR=		${CUPS_PREFIX:Q}/libexec/cups/filter
CONFIGURE_ENV+=	CUPS_FILTERS=${CUPS_FILTERDIR}
FILES_SUBST+=		CUPS_FILTERDIR=${CUPS_FILTERDIR}

TEXTTOPS_DEPENDS=	{a2ps,enscript,mpage}-[0-9]*

PKG_OPTIONS_VAR=	PKG_OPTIONS.foomatic
PKG_SUPPORTED_OPTIONS=	cups

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	MANINSTALL

.if ${OPSYS} == "SunOS"
# SunOS nroff has problems with foomatic-rip.1
MANINSTALL=	none
INSTALL_TARGET=	install-bin
.else
INSTALL_TARGET=	install-bin install-man
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
DEPENDS+=	{cups>=1.0,${TEXTTOPS_DEPENDS}}:../../print/cups15
.else
DEPENDS+=	${TEXTTOPS_DEPENDS}:../../print/mpage
.endif

DEINSTALL_TEMPLATES+=	${.CURDIR}/../../print/foomatic-filters-cups/DEINSTALL
INSTALL_TEMPLATES+=	${.CURDIR}/../../print/foomatic-filters-cups/INSTALL

EGDIR=		${PREFIX}/share/examples/foomatic
CONFDIR=	${PKG_SYSCONFDIR}/foomatic

REQD_DIRS=	${EGDIR}
OWN_DIRS=	${CONFDIR}
CONF_FILES=	${EGDIR}/filter.conf ${CONFDIR}/filter.conf

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/filter.conf ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
