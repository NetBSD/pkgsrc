# $NetBSD: common.mk,v 1.1 2020/03/30 16:52:48 riastradh Exp $

# used by finance/hledger
# used by finance/hledger-lib
# to be used by finance/hledger-ui
# to be used by finance/hledger-web

HLEDGER_VERSION=	1.17.1.1
DISTNAME=		hledger-${HLEDGER_VERSION}
PKGNAME=		${HASKELL_PKG_NAME}-${HLEDGER_VERSION}
MASTER_SITES=		${MASTER_SITE_GITHUB:=simonmichael/}
GITHUB_PROJECT=		hledger
GITHUB_TAG=		${DISTNAME}

WRKSRC=			${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}/${HASKELL_PKG_NAME}

DISTINFO_FILE=		../../finance/hledger/distinfo
