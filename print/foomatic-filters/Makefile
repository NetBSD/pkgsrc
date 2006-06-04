# $NetBSD: Makefile,v 1.12 2006/06/04 16:26:55 joerg Exp $

.include "Makefile.common"

DISTNAME=	foomatic-filters-${FOOMATIC_FILTERS_VERSION}
PKGREVISION=	4
MASTER_SITES=	http://www.linuxprinting.org/download/foomatic/

MAINTAINER=	jlam@pkgsrc.org
COMMENT=	Spooler-independent PostScript printing filter

CONFLICTS+=	foomatic-gswrapper-[0-9]*

USE_TOOLS+=	gmake gs:run perl:run
INSTALL_TARGET=	install-bin install-man

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--disable-file-converter-check

EVAL_PREFIX+=		CUPS_PREFIX=cups
CUPS_FILTERDIR=		${CUPS_PREFIX:Q}/libexec/cups/filter
CONFIGURE_ENV+= 	CUPS_FILTERS=${CUPS_FILTERDIR}
FILES_SUBST+=		CUPS_FILTERDIR=${CUPS_FILTERDIR}

TEXTTOPS_DEPENDS=	{a2ps,enscript,mpage}-[0-9]*

PKG_OPTIONS_VAR=	PKG_OPTIONS.foomatic
PKG_SUPPORTED_OPTIONS=	cups

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
DEPENDS+=	{cups>=1.0,${TEXTTOPS_DEPENDS}}:../../print/cups
.else
DEPENDS+=	${TEXTTOPS_DEPENDS}:../../print/mpage
.endif

DEINSTALL_TEMPLATE+=	${.CURDIR}/../../print/foomatic-filters-cups/INSTALL
INSTALL_TEMPLATE+=	${.CURDIR}/../../print/foomatic-filters-cups/INSTALL

EGDIR=		${PREFIX}/share/examples/foomatic
CONFDIR=	${PKG_SYSCONFDIR}/foomatic

REQD_DIRS=	${EGDIR}
OWN_DIRS=	${CONFDIR}
CONF_FILES=	${EGDIR}/filter.conf ${CONFDIR}/filter.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/filter.conf ${EGDIR}

.include "../../mk/bsd.pkg.mk"
