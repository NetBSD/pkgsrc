# $NetBSD: Makefile,v 1.2 2017/10/01 19:05:40 joerg Exp $

DISTNAME=	metasploit-payloads-1.3.9
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.metasploit.com/
COMMENT=	Compiled binaries for Metasploit\'s Meterpreter
LICENSE=	modified-bsd

CHECK_SHLIBS_SKIP+=	${GEM_LIBDIR}/data/android/libs/*

CHECK_SHLIBS_SKIP

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
