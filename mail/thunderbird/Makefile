# $NetBSD: Makefile,v 1.1.1.1 2004/04/19 23:25:27 taya Exp $

MOZILLA=	thunderbird
MOZILLA_BIN=	thunderbird-bin
MOZ_VER=	0.5
EXTRACT_SUFX=	.tar.gz
DISTNAME=	thunderbird-${MOZ_VER}-source
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/thunderbird/releases/${MOZ_VER}/ \
		ftp://ftp.mozilla.org/pub/mozilla.org/thunderbird/releases/${MOZ_VER}/

HOMEPAGE=	http://www.mozilla.org/projects/thunderbird/
COMMENT=	Redesign of the Mozilla mail client

CONFIGURE_ENV+=	MOZ_THUNDERBIRD=1
MAKE_ENV+=	MOZ_THUNDERBIRD=1

CONFIGURE_ARGS+=	--enable-extensions=wallet,spellcheck,xmlextras
MOZILLA_USE_GTK2=	# defined
MOZILLA_USE_XFT=	YES

#
# XXX
#
DISTFILES=	thunderbird-${MOZ_VER}-source.tar.gz
EXTRACT_SUFX+=	.tar.bz2
do-extract:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	extract_file="${_DISTDIR}/${DISTFILES}";			\
	export extract_file;						\
	cd ${WRKDIR}; ${EXTRACT_CMD};					\
	extract_file="${WRKDIR}/mozilla-thunderbird/archives/thunderbird-0.5-source.tar.bz2";	\
	export extract_file;						\
	${EXTRACT_CMD}

.include "../../www/mozilla/Makefile.common"
