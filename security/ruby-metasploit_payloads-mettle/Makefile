# $NetBSD: Makefile,v 1.4 2017/09/18 13:11:09 taca Exp $

DISTNAME=	metasploit_payloads-mettle-0.2.2
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.metasploit.com/
COMMENT=	Compiled binaries for Metasploit\'s next-gen Meterpreter
LICENSE=	modified-bsd

# These are pre-built binaries.
CHECK_RELRO_SKIP+=	${GEM_LIBDIR}/build/*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
