# $NetBSD: Makefile,v 1.6 2018/09/23 17:55:58 taca Exp $

DISTNAME=	metasploit-payloads-1.3.49
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.metasploit.com/
COMMENT=	Compiled binaries for Metasploit\'s Meterpreter
LICENSE=	modified-bsd

CHECK_SHLIBS_SKIP+=	${GEM_LIBDIR}/data/android/libs/*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
