# $NetBSD: Makefile,v 1.2 2004/04/26 13:56:09 taya Exp $

MOZILLA=	thunderbird
MOZILLA_BIN=	thunderbird-bin
MOZ_VER=	0.5
PKGREVISION=	1
EXTRACT_SUFX=	.tar.gz
DISTNAME=	thunderbird-${MOZ_VER}-source
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/thunderbird/releases/${MOZ_VER}/ \
		ftp://ftp.mozilla.org/pub/mozilla.org/thunderbird/releases/${MOZ_VER}/

HOMEPAGE=	http://www.mozilla.org/projects/thunderbird/
COMMENT=	Redesign of the Mozilla mail client

CONFIGURE_ENV+=	MOZ_THUNDERBIRD=1
MAKE_ENV+=	MOZ_THUNDERBIRD=1

CONFIGURE_ARGS+=	--enable-extensions=wallet,spellcheck,xmlextras

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
