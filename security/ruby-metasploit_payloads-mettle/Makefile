# $NetBSD: Makefile,v 1.26 2023/11/11 13:21:58 taca Exp $

DISTNAME=	metasploit_payloads-mettle-1.0.27
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.metasploit.com/
COMMENT=	Compiled binaries for Metasploit\'s next-gen Meterpreter
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

# These are pre-built binaries.
CHECK_RELRO_SKIP+=	${GEM_LIBDIR}/build/*
CHECK_SSP_SKIP+=	${CHECK_RELRO_SKIP}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
