# $NetBSD: options.mk,v 1.4 2008/04/12 22:43:01 jlam Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.openttd
PKG_SUPPORTED_OPTIONS=	ttd-data
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		ttd-data

.if !empty(PKG_OPTIONS:Mttd-data)
PLIST.ttd-data=		yes
LICENSE=		ttd-pseudolicense
RESTRICTED=		No redistribution allowed
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

DATAFILES=	sample.cat trg1r.grf trgcr.grf trghr.grf trgir.grf trgtr.grf
GMFILES=	00 01 02 03 04 05 06 07 08 09 10
GMFILES+=	11 12 13 14 15 16 17 18 19 20 21
GMFILES:=	${GMFILES:C/^/gm_tt/g:C/$/.gm/g}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		  ${DATAFILES:C/^/ttd\//g} ${GMFILES:C/^/ttd\//g}

DATA_DIR=	${DESTDIR}${PREFIX}/share/openttd

post-extract: post-extract-ttd-data
post-extract-ttd-data: .PHONY
	${RUN} for f in ${DATAFILES} ${GMFILES}; do \
	  cp ${DISTDIR}/ttd/$$f ${WRKDIR}; done

post-install: post-install-ttd-data
post-install-ttd-data: .PHONY
	${RUN} for f in ${DATAFILES}; do \
	  ${INSTALL_DATA} ${WRKDIR}/$$f ${DATA_DIR}/data; done
	${RUN} for f in ${GMFILES}; do \
	  ${INSTALL_DATA} ${WRKDIR}/$$f ${DATA_DIR}/gm; done
.endif
