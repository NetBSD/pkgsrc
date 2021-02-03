# $NetBSD: Makefile,v 1.12 2021/02/03 15:01:11 taca Exp $

DISTNAME=	metasploit_payloads-mettle-1.0.6
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
