# $NetBSD: Makefile,v 1.39 2023/07/09 02:34:41 taca Exp $

DISTNAME=	metasploit-payloads-2.0.148
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.metasploit.com/
COMMENT=	Compiled binaries for Metasploit\'s Meterpreter
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

CHECK_SHLIBS_SKIP+=	${GEM_LIBDIR}/data/android/libs/*
CHECK_SSP_SKIP=		${CHECK_SHLIBS_SKIP}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
