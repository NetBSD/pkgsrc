# $NetBSD: Makefile,v 1.4 2017/10/09 08:47:51 wiz Exp $

DISTNAME=	metasploit-payloads-1.3.9
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.metasploit.com/
COMMENT=	Compiled binaries for Metasploit\'s Meterpreter
LICENSE=	modified-bsd

CHECK_SHLIBS_SKIP+=	${GEM_LIBDIR}/data/android/libs/*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
