# $NetBSD: Makefile,v 1.31 2017/05/19 13:18:18 prlw1 Exp $

DISTNAME=	foomatic-filters-4.0.17
PKGREVISION=	9
CATEGORIES=	print
MASTER_SITES=	http://www.openprinting.org/download/foomatic/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.linuxprinting.org/foomatic.html
COMMENT=	Spooler-independent PostScript printing filter

CONFLICTS+=	foomatic-gswrapper-[0-9]*

USE_TOOLS+=	gmake gs:run perl pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--disable-file-converter-check
CONFIGURE_ARGS+=	--disable-dbus

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
DEPENDS+=	cups>=1.0:../../print/cups
CUPS_FILTERDIR=	${LOCALBASE}/libexec/cups/filter
CONFIGURE_ENV+=	CUPS_FILTERS=${CUPS_FILTERDIR}
FILES_SUBST+=	CUPS_FILTERDIR=${CUPS_FILTERDIR}
DEINSTALL_TEMPLATES+=	${.CURDIR}/../../print/foomatic-filters-cups/DEINSTALL
INSTALL_TEMPLATES+=	${.CURDIR}/../../print/foomatic-filters-cups/INSTALL
.else
TEXTTOPS_DEPENDS= {a2ps,enscript,mpage}-[0-9]*
DEPENDS+=	${TEXTTOPS_DEPENDS}:../../print/mpage
CONFIGURE_ENV+=	CUPS_CONFIG=/nonexistent
CONFIGURE_ENV+=	CUPS_SERVERBIN=/nonexistent
CONFIGURE_ENV+=	CUPS_FILTERS=/nonexistent
.endif

EGDIR=		${PREFIX}/share/examples/foomatic
CONFDIR=	${PKG_SYSCONFDIR}/foomatic

REQD_DIRS=	${EGDIR}
OWN_DIRS=	${CONFDIR}
CONF_FILES=	${EGDIR}/filter.conf ${CONFDIR}/filter.conf

INSTALLATION_DIRS+=	${EGDIR}
post-install:
	${INSTALL_DATA} ${WRKSRC}/filter.conf ${DESTDIR}${EGDIR}

#.include "../../print/ghostscript/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
